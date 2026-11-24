#include<iostream>
using namespace std;

class BinaryHeap
{
    private:
        static const int MAX_SIZE = 20;
        int heap[MAX_SIZE];
        int size;

        void HeapifyUp(int index)
        {
            int parent;
            while(index > 0)
            {
                parent = (index - 1) / 2;
                // MAX HEAP:
                // Child should not be greater than parent
                if(heap[index] > heap[parent])
                {
                    swap(heap[index], heap[parent]);
                    index = parent;
                }
                else
                {
                    break;
                }
            }
        }

        void HeapifyDown(int index)
        {
            int leftChild;
            int rightChild;
            int largest;

            while(true)
            {
                leftChild = 2 * index + 1;
                rightChild = 2 * index + 2;
                largest = index;

                // Compare left child: within range of the array && 
                if(leftChild < size && heap[leftChild] > heap[largest])
                {
                    largest = leftChild;
                }

                // Compare right child
                if(rightChild < size && heap[rightChild] > heap[largest])
                {
                    largest = rightChild;
                }

                // Heap property is satisfied
                if(largest == index)
                {
                    break;
                }

                // Swap parent with larger child
                int temp = heap[index];
                heap[index] = heap[largest];
                heap[largest] = temp;

                // Move downward
                index = largest;
            }
        }



    public:
        BinaryHeap()
		{ 	
			size = 0; 	
		}

        void InsertNode(int pData)
        {
            if(size == MAX_SIZE)
            {
                cout <<endl<< " Heap is Full "<< endl;
                return;
            }

            // Insert at next available position
            heap[size] = pData;

            // Increase heap size
            size++;

            // Restore Max-Heap property
            HeapifyUp(size - 1);
        }

        int DeleteNode()
        {
            if(size == 0)
            {
                cout <<endl<<" Heap is Empty "<<endl;
                return;
            }

            int toBeDeleted = heap[0];
            cout <<endl<<" Node Deleted: "<< toBeDeleted <<endl;
            
            // Replace root with last element
            heap[0] = heap[size - 1];

            // Reduce heap size
            size--;

            // Restore Heap Property
            if(size > 0)
            {
                HeapifyDown(0);
            }

            return toBeDeleted;
        }

        void Peek()
        {
            if(size == 0)
            {
                cout<<endl<<" Heap is Empty "<< endl;
                return;
            }
            cout << endl<<" Maximum Value: "<< heap[0]<< endl;
        }

        void PrintHeap()
        {
            if(size == 0)
            {
                cout<<endl<<" Heap is Empty "<<endl;
                return;
            }
            
			cout<<endl<<" Heap: ";
            for(int i = 0; i < size; i++)
            {
                cout << heap[i] << " ";
            }
            cout << endl;
        }

        void HeapSort()
        {
            int originalSize = size;
            while (size > 1)
            {
                swap(heap[0], heap[size - 1]);   // move the current max to the end
                size--;                   // that slot is now "sorted", outside the heap
                HeapifyDown(0);           // fix what's left
            }
            size = originalSize;          // so PrintHeap shows all elements
        }
};

int main()
{
    BinaryHeap heap;
    heap.InsertNode(40);
    heap.InsertNode(30);
    heap.InsertNode(60);
    heap.InsertNode(20);
    heap.InsertNode(50);
    heap.InsertNode(80);
    heap.InsertNode(70);

    cout<<endl<<" After Insertions: ";
    heap.PrintHeap();
    heap.Peek();

    heap.DeleteNode();
    cout<<endl<<" After Deletion: ";

    heap.PrintHeap();
    heap.Peek();

    return 0;
}