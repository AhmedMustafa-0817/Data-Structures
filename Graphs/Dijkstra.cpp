#include<iostream>
using namespace std;

struct Node {
    int data;
    int priority;
};

class PriorityQueue {
    Node heap[100];
    int size;

   void Swap(int a, int b) {
       Node temp = heap[a];
       heap[a] = heap[b];
       heap[b] = temp;
   }

public:
    PriorityQueue() {
        size = 0;
    }

   void Enqueue(int data, int priority) {
       heap[size].data = data;
       heap[size].priority = priority;
       int i = size++;

        while(i > 0 && heap[i].priority < heap[(i-1)/2].priority) {
            Swap(i, (i-1)/2);
            i = (i-1)/2;
        }
   }

   int Dequeue() {
       int x = heap[0].data;

        heap[0] = heap[size-1];
        size--;

        int i = 0;

        while(true) {
            int left = 2*i+1;
            int right = 2*i+2;
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

     bool Empty() {
         return size == 0;
     }
};

class Graph {
    int adj[100][100];
    int n;

public:
    Graph(int v) {
        n = v;

         for(int i=0; i<n; i++)
             for(int j=0; j<n; j++)
                 adj[i][j] = 9999;
     }

     void addEdge(int u, int v, int w) {
         adj[u][v] = w;
         adj[v][u] = w;
     }

     void Dijkstra(int start) {
         int dist[100];

         for(int i=0; i<n; i++)
             dist[i] = 9999;

         PriorityQueue pq;
         dist[start] = 0;
         pq.Enqueue(start, 0);

         while(!pq.Empty()) {
             int node = pq.Dequeue();

             for(int i=0; i<n; i++) {
                 if(adj[node][i] != 9999 &&
                    dist[node] + adj[node][i] < dist[i]) {

                      dist[i] = dist[node] + adj[node][i];
                      pq.Enqueue(i, dist[i]);
                  }
             }
         }

         for(int i=0; i<n; i++)
             cout << start << " to " << i << " = " << dist[i] << endl;
     }
};

int main() {
    Graph g(5);

     g.addEdge(0, 1, 4);
     g.addEdge(0, 2, 1);
     g.addEdge(2, 1, 2);
     g.addEdge(1, 3, 1);
     g.addEdge(2, 3, 5);
     g.addEdge(3, 4, 3);

     g.Dijkstra(0);
}