#include<iostream>
using namespace std;

#define MAX 100


class Queue
{
    int arr[MAX];
    int front;
    int rear;

public:
    Queue()
    {
        front = 0;
        rear = 0;
    }

     void Enqueue(int value)
     {
         if(rear == MAX)
         {
             cout << " Queue is Full" << endl;
             return;
         }
         arr[rear] = value;
         rear++;
     }

     int Dequeue()
     {
         int value = arr[front];
         front++;
         return value;
     }

     bool IsEmpty()
     {
         return front == rear;
     }
};
// ---------------------------------------------------------
// GRAPH CLASS
// ---------------------------------------------------------

class Graph
{
    int adjacency[MAX][MAX];
    bool visited[MAX];
    int vertices;

public:
    Graph(int v)
    {
        vertices = v;

        for(int i = 0; i < vertices; i++)
        {
            for(int j = 0; j < vertices; j++)
            {
                adjacency[i][j] = 0;
            }
        }
   }

   void AddEdge(int u, int v)
   {
       adjacency[u][v] = 1;
       adjacency[v][u] = 1;
   }

   void BFS(int start)
   {
       Queue q;

        for(int i = 0; i < vertices; i++)
        {
            visited[i] = false;
        }

        visited[start] = true;
        q.Enqueue(start);

        cout << " BFS Traversal: ";

        while(!q.IsEmpty())
        {
            int current = q.Dequeue();
            cout << current << " ";
             for(int i = 0; i < vertices; i++)
             {
                 if(adjacency[current][i] == 1 && visited[i] == false)
                 {
                     visited[i] = true;
                     q.Enqueue(i);
                 }
             }
         }

         cout << endl;
     }
};

// ---------------------------------------------------------
// MAIN FUNCTION
// ---------------------------------------------------------

int main()
{
    Graph g(5);

     g.AddEdge(0, 1);
     g.AddEdge(0, 2);
     g.AddEdge(1, 3);
     g.AddEdge(1, 4);
     g.AddEdge(2, 4);

     g.BFS(0);

     return 0;
}