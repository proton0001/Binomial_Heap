#include "MinHeap.h"



Heap::Heap(int size=MAX_HEAP_SIZE)
{
    heap = new int[size];
    HEAP_SIZE = 0;
}


Heap::~Heap()
{
    delete(heap);
}





// Some Helper Functions
// Get index of left child
int Heap::getLeftChildIndex(int index)   { return 2*(index+1) - 1;   }
// Get index of right child
int Heap::getRightChildIndex(int index)  { return 2*(index+1);       }
// Get index of Parent
int Heap::getParentIndex(int index)      { return (index-1)/2;       }
// Check if it have left child
bool Heap::hasLeftChild(int index)  { return (getLeftChildIndex(index)<MAX_HEAP_SIZE); }
// Check if it have right child
bool Heap::hasRightChild(int index) { return (getRightChildIndex(index)<MAX_HEAP_SIZE);}
// Check if it have parent
bool Heap::hasParent(int index)     { return (getParentIndex(index)>=0);}
// Get element stored in left child
int Heap::leftChild(int index)      { return heap[getLeftChildIndex(index)]; }
// Get element stored in right child
int Heap::rightChild(int index)     { return heap[getRightChildIndex(index)]; }
// Get element stored in parent
int Heap::parent(int index)     { return heap[getParentIndex(index)]; }


// Swaps values at index i and j
void Heap::swap(int i, int j)
{
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// Returns min value 
int Heap::getMin()
{
    if (HEAP_SIZE != 0)
    {
        // return top value
        return heap[0];
    }
    return -1;
}

// pop the minimum value in heap
int Heap::extractMin()
{
    // No element in heap so no min value
    if(HEAP_SIZE == 0)
    {
        return -1;
    }
    else
    {
        int item = heap[0];
        // replace top value with last value
        heap[0] = heap[HEAP_SIZE-1];
        // size decrease as we removed top
        HEAP_SIZE--;
        // Fix heap from top to down
        heapifydown();
        return item;
    }
}


// Insert a ket in heap
void Heap::insert(int val) {
    if (HEAP_SIZE == MAX_HEAP_SIZE)
    {
        std::cout << "Cannot add, Max heap size reached\n";
        return;
    }
    // Store value in last index of array
    heap[HEAP_SIZE] = val;
    HEAP_SIZE++;
    // Fix heap from bottom to top
    heapifyup();
}

// Fix heap from bottom to top
void Heap::heapifyup()
{
    int index = HEAP_SIZE-1;
    // While my value is less than parent (if there) then swap with parent
    while(hasParent(index) && parent(index) > heap[index])
    {
        swap(getParentIndex(index), index);
        index = getParentIndex(index);
    }

}

// Fix heap from top to bottom
void Heap::heapifydown()
{
    // Start from top
    int index = 0;
    // if dont have left child then definitely no right child
    while(hasLeftChild(index))
    {
        // let left = smaller child
        int smallerChildIndex = getLeftChildIndex(index);
        // if right child there then check if that min
        if(hasRightChild(index) && rightChild(index)<leftChild(index))
        {
            smallerChildIndex = getRightChildIndex(index);
        }
        // break loop if current node is smaller than smaller of child
        if (heap[index] < heap[smallerChildIndex])
        {
            break;
        }
        // Swap if smaller child if current value > min of child value
        else
        {
            swap(index, smallerChildIndex);
        }
        index = smallerChildIndex;
    }
}