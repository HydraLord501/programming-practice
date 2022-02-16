#include<iostream>
#include <list>
#include <map>
#include <vector>
// O(V +)
using namespace std;

class Graph {
    int numVertices;
    list<int> *adjLists;
    bool* visited;

    public:
        Graph(int vertices);
        void addEdge(int src, int dest);
        void DFS(int start);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
}

void Graph::DFS(int start) {
    visited[start] = true;
    list <int> adjList = adjLists[start];
    cout << start << " ";

    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); i++)
        if (!visited[*i]){
            DFS(*i);
        }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "DFS "
            " (starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}