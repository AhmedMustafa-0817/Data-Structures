#include<iostream>
using namespace std;

struct Edge {
    int u, v, weight;
};

class Graph {
    Edge edges[100];
    int n, e;

   int Find(int x, int parent[]) {
       if(parent[x] == x)
           return x;

        return Find(parent[x], parent);
   }

   void Union(int u, int v, int parent[]) {
       int a = Find(u, parent);
       int b = Find(v, parent);

        parent[a] = b;
   }

public:
    Graph(int vertices) {
        n = vertices;
        e = 0;
    }

   void addEdge(int u, int v, int w) {
       edges[e].u = u;
       edges[e].v = v;
       edges[e].weight = w;
       e++;
   }

   void Kruskal() {
       // Sort edges by weight
       for(int i = 0; i < e-1; i++) {
           for(int j = 0; j < e-i-1; j++) {
               if(edges[j].weight > edges[j+1].weight) {
                    Edge temp = edges[j];
                    edges[j] = edges[j+1];
                    edges[j+1] = temp;
                    }
             }
         }

         int parent[100];

         for(int i = 0; i < n; i++)
             parent[i] = i;

         int cost = 0, count = 0;

         for(int i = 0; i < e && count < n-1; i++) {
             int u = edges[i].u;
             int v = edges[i].v;

             if(Find(u, parent) != Find(v, parent)) {
                 cout << u << " - " << v
                      << " : " << edges[i].weight << endl;

                    cost += edges[i].weight;
                    Union(u, v, parent);
                    count++;
             }
         }

         if(count != n-1)
              cout << "MST does not exist";
         else
              cout << "MST Cost: " << cost;
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

     g.Kruskal();

     return 0;
}