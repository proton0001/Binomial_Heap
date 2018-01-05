#ifndef BinomialHeap_h
#define BinomialHeap_h

#include <iostream>
#include <climits>
#include "MinHeap.h"
using namespace std;

class Node {
public:
    int data;
    int degree;
    struct Node * child;
    struct Node * sibling;
    struct Node * parent;
public:
    Node(int key);
};

class BinomialHeap
{
    private:
        Node *Head;
        Node *RevList;
        int count;
    public:
        int minimumKey(); // Return minimum key in binomialHeap
        Node* initializeheap(); //Initialize Heap to NULL (Empty)
        int binomialLink(Node* node1, Node* node2); // Links 2 node in tree
        Node* createNode(int key); // Create a node with NULL child, sibling, parent and given key 
        Node* Insert(int key); // Insert Key in Binomial Node
        Node* Union(Node* H1, Node* H2); // Union of 2 heaps
        Node* Merge(Node* H1, Node* H2); // Merge 2 heaps
        int Display(Node* H);   // Display heap with root = H
        Node* Search(Node* H, int key); // Search for a key in Binomial Heap
        Node* Search(int key); // Search for a key in Binomial Heap
        int Decrease_key(Node* H, int i, int k); // Decrease key of a node in Binomial Heap
        int Delete(Node* H, int k); // Delete a key from heap
        int Delete(int k); // Delete a key from heap
        bool isNotEmpty(); // check if empty binomial heap
        int Decrease_key(int oldkey, int newkey); // Decrease key of a node in Binomial Heap
        int Display(); // Display complete binomial heap
        void printit(Node *node); // Print node and it sibling, children
        int DisplayAll(); // Display entire Tree
        Node* Extract_Min(); // Extract minimum node
        // Constructor
        BinomialHeap()
        {
            Head = initializeheap();
            int count = 1;
        }
};

#endif



