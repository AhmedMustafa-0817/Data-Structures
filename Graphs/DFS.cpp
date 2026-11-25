#include <iostream>
using namespace std;

class Graph {
    int adj[100][100] = {0};
    int n;

    public:
    Graph(int vertices) {
        n = vertices;
    }

    void addEdge(int u, int v) {
        adj[u][v] = adj[v][u] = 1;
    }

    void DFS(int node, bool visited[]) {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i]) {
                DFS(i, visited);
            }
        }
    }

    void startDFS(int start) {
        bool visited[100] = {false};
        DFS(start, visited);
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    g.startDFS(0);
}