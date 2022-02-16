#include<iostream>
#include <list>
// O(V + E)
using namespace std;

class Graph {
    int numVertices;
    list<int>*  adjLists;
    bool* visited;

    public:
        Graph(int vertices);
        void addEdge(int src, int dest);
        void BFS(int start);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
}

void Graph::BFS(int start) {
    visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }    
    list<int> queue;
    visited[start] = true;
    queue.push_back(start);
    cout << start;
    list<int>::iterator i;

    while(!queue.empty()) {
        int current = queue.front();

        if(current != start) {
            cout << "->" << current;
        }

        queue.pop_front();

        for (i = adjLists[current].begin(); i != adjLists[current].end(); i++) {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}