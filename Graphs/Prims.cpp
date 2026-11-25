#include<iostream>
using namespace std;

struct Node
{
    int data;
    int priority;
};

class PriorityQueue
{
    Node heap[100];
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

   bool Empty()
   {
       return size == 0;
   }

   void Enqueue(int data, int priority)
   {
       if(size == 100)
           return;

        heap[size].data = data;
        heap[size].priority = priority;

        int i = size;
        size++;

        // Heapify Up
        while(i > 0 && heap[i].priority < heap[(i - 1) / 2].priority)
        {
             Swap(i, (i - 1) / 2);
             i = (i - 1) / 2;
         }
     }

     Node Dequeue()
     {
         Node x = heap[0];

         heap[0] = heap[size - 1];
         size--;

         // Heapify Down
         int i = 0;

         while(true)
         {
             int left = 2 * i + 1;
             int right = 2 * i + 2;
             int smallest = i;

             if(left < size && heap[left].priority < heap[smallest].priority)
                 smallest = left;

            if(right < size && heap[right].priority <
heap[smallest].priority)
                smallest = right;

             if(smallest == i)
                 break;

             Swap(i, smallest);
             i = smallest;
         }

         return x;
     }
};

class Graph
{
    int adj[100][100];
    int n;

public:
    Graph(int vertices)
    {
        n = vertices;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            adj[i][j] = 9999;
        }
    }
}

void addEdge(int u, int v, int w)
{
    adj[u][v] = w;
    adj[v][u] = w;
}

void Prim(int start)
{
    bool visited[100] = {false};

    PriorityQueue pq;

    pq.Enqueue(start, 0);

    int cost = 0;
    int count = 0;

    while(!pq.Empty())
    {
        Node temp = pq.Dequeue();

        int node = temp.data;

        if(visited[node])
            continue;

        visited[node] = true;

        cost += temp.priority;
        count++;

        for(int i = 0; i < n; i++)
        {
            if(adj[node][i] != 9999 && !visited[i])
            {
                pq.Enqueue(i, adj[node][i]);
            }
        }
    }
         if(count != n)
         {
              cout << "MST does not exist. Graph is disconnected." << endl;
         }
         else
         {
              cout << "MST Cost: " << cost << endl;
         }
     }
};

int main()
{
    Graph g(5);

     g.addEdge(0, 1, 4);
     g.addEdge(0, 2, 1);
     g.addEdge(2, 1, 2);
     g.addEdge(1, 3, 1);
     g.addEdge(2, 3, 5);
     g.addEdge(3, 4, 3);

     g.Prim(0);

     return 0;
}