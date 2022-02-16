#include <iostream>
#include <vector>
// O(V)
using namespace std;

void addEdge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v) {
        cout << "\n Vertex " << v
             << "\n contains ";
        for (auto x : adj[v])
            cout << "-> " << x;
        cout<<endl;
    }
}

int main()
{
    int size = 5;
    vector<int> adj[size];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, size);
    return 0;
}