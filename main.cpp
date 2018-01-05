#include "BinomialHeap.h"


int main()
{
	// Initialize new Binomial heap
    BinomialHeap *heap = new BinomialHeap();
    cout << "**** BinomialHeap Implementation ****\n";
    int i, data, key, oldkey, newkey;
    Node *temp;
    Node * x;
    while (true)
    {
        cout << "\n____________________________________________________________________\n1. Insert\n2. Extract Min.\n3. Print Minimum Key.\n4. Display Roots Nodes Only\n5. Display All Nodes Rootwise\n6. Search Key\n7. Decrease key\n8. Delete \n9. Exit.\n=> ";
        cin >> i;
        switch(i)
        {
        	// Insert a key
            case 1:
            	cout << "Enter Key\n=> ";
            	cin >> key;
	            heap->Insert(key);
	            break;
            // Extract minimum key
            case 2:
	            x = heap->Extract_Min();
	            if(x)
		            cout << "Node with key " << x->data << " deleted";
	            else
		            cout << "Heap is empty";
	            break;
	        // Print minimum key without deleting it
            case 3:
	            if(heap->isNotEmpty())
		            cout << "Node with minimum key : " << heap->minimumKey() << "\n";
	            else
		            cout << "Heap is empty";         
	            break;
	        // Display root nodes
	        case 4:
	        	heap->Display();
	        	break;
	        // Display entire Binomial heap
	        case 5:
	        	heap->DisplayAll();
	        	break;
	        // Saerch a key in Binomial Heap
	        case 6:
	        	cout << "Enter Key to Search = ";
	        	cin >> key;
	        	temp = heap->Search(key);
	        	if(temp)
	        	{
	        		cout << "Key is present in binomial heap\n";
	        	}
	        	else
	        	{
	        		cout << "Key not found\n";
	        	}
	        	break;
	        // Decrease a node's key value in binomial heap
	        case 7:
	        	cout << "Enter Key to Decrease = ";
	        	cin >> oldkey;
	        	cout << "Enter New KeyVal = ";
	        	cin >> newkey;
	        	heap->Decrease_key(oldkey, newkey);
		        break;
	        // Delete a node from tree
	        case 8:
	        	cout << "Enter key value to delete = ";
	        	cin >> key;
	        	heap->Delete(key);
	        	break;
		    // Exit
	        case 9:
		        return 0;
		    default:
		    	cout << "Invalid Response, Try again :(\n";
	        	   	
        }
	} 
	return 0;
}
