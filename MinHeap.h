#ifndef Heap_h
#define Heap_h

#include <iostream>

#ifndef MAX_HEAP_SIZE
#define MAX_HEAP_SIZE 100
#endif



class Heap {
private:
	int getLeftChildIndex(int index);
	int getRightChildIndex(int index);
	int getParentIndex(int index);
	bool hasLeftChild(int index);
	bool hasRightChild(int index);
	bool hasParent(int index);
	int leftChild(int index);
	int rightChild(int index);
	int parent(int index);
	void swap(int i, int j);
	void heapifyup();
	void heapifydown();

public:
	Heap(int size);
	~Heap();
	int *heap; // Heap Array
	int HEAP_SIZE; // Store Heap Size
	int extractMin();
	void insert( int val);
	int getMin();
};
#endif