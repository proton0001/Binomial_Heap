#include "BinomialHeap.h"

Node::Node(int key)
{
	this->data = key;
    this->degree = 0;
    this->child = NULL;
    this->sibling = NULL;
    this->parent = NULL;
}


// Traverse throught top link and get minimum Node
int BinomialHeap::minimumKey()
{
    Node *minNode = NULL;
    Node *curr = this->Head;
    int min = INT_MAX;
    // While we reach end
    while(curr != NULL) 
    {
    	// if current mininum > current->data then min is that data
        if(curr->data < min)
        {
            min = curr->data;
            minNode = curr;
        }
        curr = curr->sibling;
    }
    // return minimum data value
    return minNode->data;
}

// Create a new Empty Heap (node with null value)
Node* BinomialHeap::initializeheap()
{
    Node* np = NULL;
    return np;
}



// Link two Min Heaps(2 trees)
int BinomialHeap::binomialLink(Node* node1, Node* node2)
{
    node1->parent = node2;
    node1->sibling = node2->child;
    node2->child = node1;
    node2->degree += 1;
}


// New node with data = key
Node* BinomialHeap::createNode(int key)
{
    return (new Node(key));
}

// Insert a node with data = key in binomial heap 
Node* BinomialHeap::Insert(int key)
{
    Head = Union(Head, new Node(key));
    return Head;
}
 
//Union Nodes in Binomial Heap
Node* BinomialHeap::Union(Node* H1, Node* H2)
{
    Node *H = Merge(H1, H2); // Merge Both Binomial Heaps
    // If both were empty then  Merged is empty
    if (H == NULL)
        return H;
    Node* prev= NULL;
    Node* curr = H;
    Node* next = curr->sibling;
    // Iterate over merged Binomial heap and combine two heaps if same degree
    while (next != NULL)
    {
        // Current node have different degree than next if it exist
	    if 	((curr->degree != next->degree) || ((next->sibling != NULL) && next->sibling->degree == curr->degree))
        {
            prev = curr;
            curr = next;
        }
        // Same degree then combine both
        else
	    {
            // check if cur have lower data value
            // then make it main root and make next as child of current
            if (curr->data <= next->data)
            {
                curr->sibling = next->sibling;
                binomialLink(next, curr);
            }
            // Otherwise if next have lower data
            else
            {
                // Make prev point to next element and next element (and make if main node, i.e curr as child of next)
                if (prev == NULL)
                {    
                    H = next;
                }
                else
                {
                    prev->sibling = next;
                }
                // Link current and next node
                binomialLink(curr, next);
                curr = next;
            }
	    }
        next = curr->sibling;
    }
    // Return Union of heaps
    return H;
}

 // * Merge Nodes in Binomial Heap in order of increasing degree
Node* BinomialHeap::Merge(Node* H1, Node* H2)
{
    Node* MergedHeap = NULL;
    Node* node_heap1 = H1;
    Node* node_heap2 = H2;
    Node* a;
    Node* b;
    // If Heap1 is not null
    if (node_heap1 != NULL)
    {
    	// If Heap2 is not null
        if (node_heap2 != NULL)
        {
        	// Heap 1 is of lower degree then heap1 is first
            if (node_heap1->degree <= node_heap2->degree)
                MergedHeap = node_heap1;
            // Heap 2 is of lower degree then heap2 is first
            else if (node_heap1->degree > node_heap2->degree)
                MergedHeap = node_heap2;
        }
        // If heap 2 is null and heap1 is not null then heap1 is merged heap
        else
            MergedHeap = node_heap1;
    }
    // Heap 1 is empty then merged = heap2
    else
        MergedHeap = node_heap2;
    // Add the remaining heap's node
    while (node_heap1 != NULL && node_heap2 != NULL)
    {
    	// add the 
        if (node_heap1->degree < node_heap2->degree)
        {
            node_heap1 = node_heap1->sibling;
        }
        // If same degree then take first one first 
        else if (node_heap1->degree == node_heap2->degree)
        {
            a = node_heap1->sibling;
            node_heap1->sibling = node_heap2;
            node_heap1 = a;
        }
        // Else second one comes first
        else
        {
            b = node_heap2->sibling;
            node_heap2->sibling = node_heap1;
            node_heap2 = b;
        }
    }
    return MergedHeap;
}

 // Display Binomial Heap (called with root node, for local functions)
int BinomialHeap::Display(Node* H)
{
    // Empty BionialHeap
    if (H == NULL)
    {
        cout<<"The BionialHeap is empty"<<endl;
        return 0;
    }
    cout<<"The root nodes are: "<<endl;
    Node* curr;
    curr = H;
    // Iterate over all root nodes
    while (curr != NULL)
    {
        cout << curr->data;
        if (curr->sibling != NULL)
            cout<<" --> ";
        curr = curr->sibling;
    }
    cout << endl;
}
// Display Binomial Heap ( for onject use as they cant call using root node)
int BinomialHeap::Display()
{
    Node *H = Head;
    if (H == NULL)
    {
        cout<<"The Heap is empty"<<endl;
        return 0;
    }
    cout<<"The root nodes are: "<<endl;
    Node* curr;
    curr = H;
    // Iterate over all root nodes
    while (curr != NULL)
    {
        cout << curr->data;
        if (curr->sibling != NULL)
            cout<<" --> ";
        curr = curr->sibling;
    }
    cout << endl;
}
// Display Root as well as its corresponding heap
int BinomialHeap::DisplayAll()
{
    // Check if head is empty
    Node *H = Head;
    if (H == NULL)
    {
        cout<<"The Heap is empty"<<endl;
        return 0;
    }
    cout<<"The nodes are: "<<endl;
    Node *temp = Head;
    // Iterate over all roots
    while(temp != NULL)
    {
        cout << "Root = "<< temp->data << " Nodes : " << temp->data << " "; 
        // If it have child then print it
        if(temp->child)
        {
            printit(temp->child);
        }
        cout << endl;
        // go to next root
        temp = temp->sibling;
    }
    cout << endl;
}

// Print nodes of child of heap
void BinomialHeap::printit(Node *node)
{
    if(node == NULL)
        return;
    std::cout << node->data << " ";
    // If sibling exist then print it
    if(node->sibling != NULL)
    {
        printit(node->sibling);
    }
    // If it have child, print it
    if(node->child != NULL)
    {
        printit(node->child);
    }
}

// Extract Minimum from BinomialHeap
Node* BinomialHeap::Extract_Min()
{
    if (Head == NULL)
    {
        cout << "Nothing to Extract" << endl;
        return NULL;
    }
    Node* curr = Head;
    Node* prev = NULL;
    int min_data = Head->data;
    Node* min_node = Head;
    // Iterate over all root and find minimum data and node
    while (curr->sibling != NULL)
    {
        if (curr->sibling->data < min_data)
        {
            min_data = curr->sibling->data;
            min_node = curr->sibling;
            prev = curr;
        }
        curr = curr->sibling;
    }
    if (prev == NULL && min_node->sibling == NULL)
    {
        Head = NULL;
    }
    else if (prev == NULL)
    {
        Head = min_node->sibling;
    }
    else if (prev->sibling == NULL)
    {
        prev = NULL;
    }
    else
    {
        prev->sibling = min_node->sibling;
    }
    // Reverse list of child node
    if(min_node->child)
    {
        Node *next = NULL;
        prev = NULL;
        curr = min_node->child;
        while(curr)
        {
            curr->parent = NULL;
            next = curr->sibling;
            curr->sibling = prev;
            prev = curr;
            curr = next;
        }
    }
    // Take union of Heap without heap with min_key and children of min_key node
    Head = Union(Head, prev);
    return min_node;
}

 

// Search Nodes in Binomial Heap
Node* BinomialHeap::Search(Node* H, int key)
{
    // Base case, Null Node
    if(H == NULL)
    {
        return NULL;
    }
    Node* curr = H;
    Node* temp = NULL;
    // If current node is the node
    if (curr->data == key)
    {
        return curr;
    }
    // If it have child
    if (curr->child != NULL)
        temp = Search(curr->child, key);
    // If if have sibling and key was not found in child node subheap
    if (curr->sibling != NULL && temp == NULL)
        temp = Search(curr->sibling, key);
    return temp;
}


// Search for a key, object calls this
Node* BinomialHeap::Search(int key)
{
    if(Head)
        return Search(Head, key);
    else
        return NULL;
}

// Deacrease value of a key in BinomialHeap
int BinomialHeap::Decrease_key(int oldkey, int newkey)
{
    Decrease_key(Head, oldkey, newkey);    
}


// Decrease key of a Node 
int BinomialHeap::Decrease_key(Node* H, int oldkey, int newkey)
{
    int temp;
    Node* temp_node1;
    Node* y;
    Node* z;
    temp_node1 = Search(H, oldkey);
    // IF not found then invalid key
    if (temp_node1 == NULL)
    {
        cout<<"Invalid choice of key"<<endl;
        return 0;
    }
    // If greater key was entered
    if (newkey > temp_node1->data)
    {
        cout<<"Error!! New key is greater than current key"<<endl;
        return 0;
    }
    // Fix heap towards up
    temp_node1->data = newkey;
    y = temp_node1;
    z = temp_node1->parent;
    // keep swaping while parent have greater key than child
    while (z != NULL && y->data < z->data)
    {
        temp = y->data;
        y->data = z->data;
        z->data = temp;
        y = z;
        z = z->parent;
    }
}

int BinomialHeap::Delete(int k)
{
    Delete(Head, k);
}
// Delete Nodes in Binomial Heap 
int BinomialHeap::Delete(Node* H, int k)
{
    Node* np;
    if (H == NULL)
    {
        cout<<"\nHEAP EMPTY!!!!!";
        return 0;
    }
    Decrease_key(H, k, INT_MIN);
    np = Extract_Min();
    if (np != NULL)
        cout<<"Node Deleted Successfully"<<endl;
}

// To check if non empty Binomial Heap
bool BinomialHeap::isNotEmpty()
{
    if(Head)
    {
        return true;
    }
    return false;
}