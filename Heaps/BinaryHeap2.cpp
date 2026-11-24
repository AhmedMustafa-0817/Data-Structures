#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node()
        {
            data = 0;
        }
};

// ---------------------------------------------------------
// BINARY HEAP CLASS
// ---------------------------------------------------------

class BinaryHeap
{
    private:
        static const int MAX_SIZE = 50;
        node heap[MAX_SIZE];
        int size;
        int heapType;

        // -------------------------------------------------
        // CHECK PRIORITY
        // -------------------------------------------------

        bool HigherPriority(int value1, int value2)
        {
            // Max Heap
            if(heapType == 1)
            {
                return value1 > value2;
            }
            // Min Heap
            else
            {
                return value1 < value2;
            }
        }

        // -------------------------------------------------
        // SWAP TWO NODES
        // -------------------------------------------------

        void SwapNodes(int index1, int index2)
        {
            int temp;

            temp = heap[index1].data;

            heap[index1].data = heap[index2].data;

            heap[index2].data = temp;
        }

        // -------------------------------------------------
        // HEAPIFY-UP
        // ITERATIVE VERSION
        // -------------------------------------------------

        void HeapifyUp(int index)
        {
            int parent;
            while(index > 0)
            {
                parent = (index - 1) / 2;

                // Heap property violated
                if(HigherPriority(heap[index].data,
                                  heap[parent].data))
                {
                    SwapNodes(index, parent);
                    // Move upward
                    index = parent;
                }
                else
                {
                    break;
                }
            }
        }

        // -------------------------------------------------
        // HEAPIFY-DOWN
        // ITERATIVE VERSION
        // -------------------------------------------------

        void HeapifyDown(int index)
        {
            int leftChild;
            int rightChild;
            int priorityIndex;
            while(true)
            {
                leftChild = 2 * index + 1;
                rightChild = 2 * index + 2;

                // Initially parent has priority
                priorityIndex = index;

                // Compare left child
                if(leftChild < size &&
                   HigherPriority(heap[leftChild].data,
                                  heap[priorityIndex].data))
                {
                    priorityIndex = leftChild;
                }

                // Compare right child
                if(rightChild < size &&
                   HigherPriority(heap[rightChild].data,
                                  heap[priorityIndex].data))
                {
                    priorityIndex = rightChild;
                }

                // Heap property is satisfied
                if(priorityIndex == index)
                {
                    break;
                }

                // Swap parent with appropriate child
                SwapNodes(index, priorityIndex);

                // Move downward
                index = priorityIndex;
            }
        }

        // -------------------------------------------------
        // RECURSIVE HEAPIFY-UP
        // Alternative version
        // -------------------------------------------------

        void HeapifyUpRecursive(int index)
        {
            if(index == 0)
            {
                return;
            }

            int parent = (index - 1) / 2;

            if(HigherPriority(heap[index].data,
                              heap[parent].data))
            {
                SwapNodes(index, parent);
                HeapifyUpRecursive(parent);
            }
        }

        // -------------------------------------------------
        // RECURSIVE HEAPIFY-DOWN
        // Alternative version
        // -------------------------------------------------

        void HeapifyDownRecursive(int index)
        {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int priorityIndex = index;

            if(leftChild < size &&
               HigherPriority(heap[leftChild].data,
                              heap[priorityIndex].data))
            {
                priorityIndex = leftChild;
            }

            if(rightChild < size &&
               HigherPriority(heap[rightChild].data,
                              heap[priorityIndex].data))
            {
                priorityIndex = rightChild;
            }

            if(priorityIndex != index)
            {
                SwapNodes(index, priorityIndex);
                HeapifyDownRecursive(priorityIndex);
            }
        }

    public:

        // -------------------------------------------------
        // CONSTRUCTOR
        // heapType = 1 -> Max Heap
        // heapType = 2 -> Min Heap
        // -------------------------------------------------

        BinaryHeap(int type)
        {
            size = 0;
            heapType = type;
        }

        // -------------------------------------------------
        // INSERT NODE
        // -------------------------------------------------

        void InsertNode(int pData)
        {
            if(size == MAX_SIZE)
            {
                cout << endl
                     << "Heap is Full"
                     << endl;
                return;
            }


            // Insert at next available position
            heap[size].data = pData;

            // Increase heap size
            size++;

            // Restore Heap Property
            HeapifyUp(size - 1);
        }

        // -------------------------------------------------
        // DELETE ROOT NODE
        // -------------------------------------------------

        void DeleteNode()
        {
            if(size == 0)
            {
                cout << endl
                     << "Heap is Empty"
                     << endl;

                return;
            }

            cout << endl
                 << "Node Deleted: "
                 << heap[0].data
                 << endl;

            // Replace root with last element
            heap[0].data =
                heap[size - 1].data;

            // Reduce heap size
            size--;

            // Restore Heap Property
            if(size > 0)
            {
                HeapifyDown(0);
            }
        }

        // -------------------------------------------------
        // PEEK
        // -------------------------------------------------

        void Peek()
        {
            if(size == 0)
            {
                cout << endl
                     << "Heap is Empty"
                     << endl;

                return;
            }

            if(heapType == 1)
            {
                cout << endl
                     << "Maximum Value: "
                     << heap[0].data
                     << endl;
            }

            else
            {
                cout << endl
                     << "Minimum Value: "
                     << heap[0].data
                     << endl;
            }
        }

        // -------------------------------------------------
        // PRINT HEAP
        // -------------------------------------------------

        void PrintHeap()
        {
            if(size == 0)
            {
                cout << endl
                     << "Heap is Empty"
                     << endl;
                return;
            }

            cout << endl
                 << "Heap: ";

            for(int i = 0; i < size; i++)
            {
                cout << heap[i].data << " ";
            }

            cout << endl;
        }

        // -------------------------------------------------
        // BUILD HEAP - BOTTOM UP
        // -------------------------------------------------

        void BuildHeap(int arr[], int n)
        {
            if(n > MAX_SIZE)
            {
                cout << endl
                     << "Too Many Elements"
                     << endl;
                return;
            }

            // Copy array into heap
            for(int i = 0; i < n; i++)
            {
                heap[i].data = arr[i];
            }
            size = n;


            // Start from last non-leaf node
            for(int i = size / 2 - 1;
                i >= 0;
                i--)
            {
                HeapifyDown(i);
            }
        }

        // -------------------------------------------------
        // BUILD HEAP USING REPEATED INSERTION
        // -------------------------------------------------

        void BuildHeapByInsertion(int arr[], int n)
        {
            size = 0;
            for(int i = 0; i < n; i++)
            {
                InsertNode(arr[i]);
            }
        }
};


// ---------------------------------------------------------
// MAIN FUNCTION
// ---------------------------------------------------------

int main()
{
    // ============================================
    // MAX HEAP
    // ============================================

    BinaryHeap maxHeap(1);

    maxHeap.InsertNode(40);
    maxHeap.InsertNode(30);
    maxHeap.InsertNode(60);
    maxHeap.InsertNode(20);
    maxHeap.InsertNode(50);
    maxHeap.InsertNode(80);
    maxHeap.InsertNode(70);

    cout << endl
         << "MAX HEAP";
    maxHeap.PrintHeap();

    maxHeap.Peek();

    maxHeap.DeleteNode();

    cout << endl
         << "After Deletion:";

    maxHeap.PrintHeap();

    // ============================================
    // MIN HEAP
    // ============================================

    BinaryHeap minHeap(2);

    minHeap.InsertNode(40);
    minHeap.InsertNode(30);
    minHeap.InsertNode(60);
    minHeap.InsertNode(20);
    minHeap.InsertNode(50);
    minHeap.InsertNode(80);
    minHeap.InsertNode(70);

    cout << endl
         << endl
         << "MIN HEAP";

    minHeap.PrintHeap();

    minHeap.Peek();

    minHeap.DeleteNode();

    cout << endl
         << "After Deletion:";

    minHeap.PrintHeap();

    // ============================================
    // BUILD HEAP EXAMPLE
    // ============================================

    int arr[] =
    {
        20, 35, 15, 40, 80, 10, 60
    };

    int n =
        sizeof(arr) / sizeof(arr[0]);


    BinaryHeap buildMaxHeap(1);

    buildMaxHeap.BuildHeap(arr, n);

    cout << endl
         << endl
         << "Bottom-Up Max Heap:";

    buildMaxHeap.PrintHeap();

    return 0;
}