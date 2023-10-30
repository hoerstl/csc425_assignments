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
  return loc;
}

void
freeList::free_space( long int* location ) {
  return;
  if (location[1] != 1234567){
    cout << "Invalid Magic Number " << location[1] << " read. Expected 1234567." << endl;
    return;
  }
  location[1] = (long int)head;
  head = location;
}

void
freeList::coalesce_forward() {
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
