#include<iostream>
using namespace std;


class MaxHeap
{
    int heap[100];
    int size;

   void Swap(int a, int b)
   {
       int temp = heap[a];
       heap[a] = heap[b];
       heap[b] = temp;
   }

   void HeapifyUp(int i)
   {
       while(i > 0 && heap[i] > heap[(i - 1) / 2])
       {
           Swap(i, (i - 1) / 2);
           i = (i - 1) / 2;
       }
   }

   void HeapifyDown(int i)
   {
       while(true)
       {
           int left = 2 * i + 1;
           int right = 2 * i + 2;
           int largest = i;

           if(left < size && heap[left] > heap[largest])
               largest = left;
           if(right < size && heap[right] > heap[largest])
               largest = right;

           if(largest == i)
               break;

           Swap(i, largest);
           i = largest;
         }
     }

public:
    MaxHeap()
    {
        size = 0;
    }

     void Insert(int value)
     {
         if(size == 100)
         {
             cout << " Heap is Full" << endl;
             return;
         }

         heap[size] = value;
         size++;
         HeapifyUp(size - 1);
     }

     void Delete()
     {
         if(size == 0)
         {
             cout << " Heap is Empty" << endl;
             return;
         }

         cout << " Removed: " << heap[0] << endl;

         heap[0] = heap[size - 1];
         size--;
         HeapifyDown(0);
     }

     void Display()
     {
         cout << " Max Heap: ";
         for(int i = 0; i < size; i++)
             cout << heap[i] << " ";
         cout << endl;
     }
};


class MinHeap
{
    int heap[100];
    int size;

   void Swap(int a, int b)
   {
       int temp = heap[a];
       heap[a] = heap[b];
       heap[b] = temp;
   }

   void HeapifyUp(int i)
   {
       while(i > 0 && heap[i] < heap[(i - 1) / 2])
       {
           Swap(i, (i - 1) / 2);
           i = (i - 1) / 2;
       }
   }

   void HeapifyDown(int i)
   {
       while(true)
       {
           int left = 2 * i + 1;
           int right = 2 * i + 2;
           int smallest = i;

            if(left < size && heap[left] < heap[smallest])
                smallest = left;
            if(right < size && heap[right] < heap[smallest])
                smallest = right;

            if(smallest == i)
                break;

            Swap(i, smallest);
            i = smallest;
        }
   }

public:
    MinHeap()
    {
        size = 0;
    }
     void Insert(int value)
     {
         if(size == 100)
         {
             cout << " Heap is Full" << endl;
             return;
         }

         heap[size] = value;
         size++;
         HeapifyUp(size - 1);
     }

     void Delete()
     {
         if(size == 0)
         {
             cout << " Heap is Empty" << endl;
             return;
         }

         cout << " Removed: " << heap[0] << endl;

         heap[0] = heap[size - 1];
         size--;
         HeapifyDown(0);
     }

     void Display()
     {
         cout << " Min Heap: ";
         for(int i = 0; i < size; i++)
             cout << heap[i] << " ";
         cout << endl;
     }
};


int main()
{
    MaxHeap maxH;
    maxH.Insert(40);
    maxH.Insert(30);
    maxH.Insert(60);
    maxH.Insert(20);
    maxH.Insert(50);
    maxH.Display();
    maxH.Delete();
    maxH.Display();

    return 0;
}