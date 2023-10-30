#include "freeList.h"

freeList::freeList( long int*inRAM, int size ) {
  // the inRAM pointer is a pointer to the start of the ram
  head = inRAM;
  head[0] = size - 2; // We store the size of the free space first
  head[1] = (long int) NULL; // We store the pointer to the next node second
}

long int*
freeList::reserve_space( int size ) {
  // size is the number of long ints to reserve
  long int* loc = head;
  long int* previousLoc = (long int*) 0;
  while (loc != 0){
    if (loc[0] >= size){
      // Split the free block
      long int *startFreeChunk = loc + 2;
      long int *newFreeNode = startFreeChunk + size;
      newFreeNode[0] = loc[0] - size - 2;
      newFreeNode[1] = loc[1];
      // Now we alter the target node to become a header for allocated space
      loc[0] = size;
      //cout << "Planting a magic number at (0x" << hex << loc + 1 << ")." << endl;
      loc[1] = 1234567; // Magic number
      // We make the previous node in the free list point to our new node
      if (previousLoc){
        previousLoc[1] = (long int)newFreeNode;
      } else{
        head = newFreeNode;
      }
      break;
    }
    previousLoc = loc;
    loc = (long int*)loc[1];
  }
  if (loc == 0){
    return (long int*)-1;
  }
  return loc+2;
}

void
freeList::free_space( long int* location ) {
  long int* header = location - 2;
  if (header[1] != 1234567){
    cout << "Invalid Magic Number " << header[1] << " at (" << hex << header+1 << "). Expected 1234567." << endl;
    return;
  }
  // I'm going to keep the free list sorted in order so let's find the correct node shall we?
  long int *infimum = NULL;
  long int *suprimum = head;
  while(suprimum != 0 && header > suprimum){
    infimum = suprimum;
    suprimum = (long int*)(suprimum[1]);
  }
  if (infimum){
    infimum[1] = (long int)header;
  } else{
    head = header;
  }
  header[1] = (long int)suprimum;
}

void
freeList::coalesce_forward() {
  long int* current = head;
  while (current){
    // check to see if this node can merge with the one in front of it
    if (current+current[0]+2 == (long int*)(current[1])){
      // Merge the nodes
      current[0] += ((long int*)(current[1]))[0] + 2;
      current[1] = ((long int*)(current[1]))[1];
      continue;
    }
    current = (long int*)(current[1]);
  }
}

// print() is given to you. It traverses the free list and prints out what is there.
void freeList::print() {
  long int * printHead = head;
  
  while( printHead != NULL ) {
    cout << "at " << printHead << "("<< dec <<printHead[0] << " : 0x" << hex << printHead[1] <<  ")\n";
    printHead = (long int *)printHead[1];
  }
  cout << endl;
}
