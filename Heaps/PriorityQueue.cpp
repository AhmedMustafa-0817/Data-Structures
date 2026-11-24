#include<iostream>
using namespace std;

struct Node
{
    char data;
    int priority;
};

class PriorityQueue   // using max heap
{
    Node heap[20];
    int size;

   void Swap(int a, int b)
   {
       Node temp = heap[a];
       heap[a] = heap[b];
       heap[b] = temp;
   }

public:
    PriorityQueue()
    {
        size = 0;
    }

   void Enqueue(char data, int priority)
   {
       heap[size].data = data;
       heap[size].priority = priority;
       int i = size;
       size++;

        // Heapify Up
        while(i > 0 && heap[i].priority > heap[(i - 1) / 2].priority)
        {
            Swap(i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
   }

   void Dequeue()
   {
       if(size == 0)
       {
             cout << " Queue is Empty" << endl;
             return;
         }

        cout << " Removed: " << heap[0].data << " (" << heap[0].priority <<
")" << endl;

         heap[0] = heap[size - 1];
         size--;

         // Heapify Down
         int i = 0;
         while(true)
         {
             int left = 2 * i + 1;
             int right = 2 * i + 2;
             int largest = i;

             if(left < size && heap[left].priority > heap[largest].priority)
                 largest = left;
             if(right < size && heap[right].priority > heap[largest].priority)
                 largest = right;

             if(largest == i)
                 break;

             Swap(i, largest);
             i = largest;
         }
     }
};

int main()
{
    PriorityQueue pq;
    pq.Enqueue('A', 2);
    pq.Enqueue('B', 5);
    pq.Enqueue('C', 1);
    pq.Enqueue('D', 4);

     pq.Dequeue();
     pq.Dequeue();
     pq.Dequeue();
     pq.Dequeue();

     return 0;
}