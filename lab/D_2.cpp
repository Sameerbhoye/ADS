#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;  // Number of vertices
    vector<vector<int>> adj;  // Adjacency list

    // Helper function for DFS
    void countPathsUtil(int u, int d, vector<bool> &visited, int &pathCount) {
        if (u == d) {
            pathCount++;  // Reached destination
        } else {
            visited[u] = true;  // Mark the current node as visited

            // Recur for all adjacent vertices
            for (int i : adj[u]) {
                if (!visited[i]) {
                    countPathsUtil(i, d, visited, pathCount);
                }
            }

            visited[u] = false;  // Backtrack
        }
    }

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Function to count all paths between u and d
    int countPaths(int u, int d) {
        vector<bool> visited(V, false);
        int pathCount = 0;
        countPathsUtil(u, d, visited, pathCount);
        return pathCount;
    }
};

int main() {
    Graph g(5);  // Assuming 5 vertices labeled 0 to 4

    // Adding edges based on the given graph image
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 4);

    int startVertex = 0;  // For example, starting from vertex A (0)
    int endVertex = 4;    // Ending at vertex E (4)

    cout << "Total paths between " << startVertex << " and " << endVertex << ": "
         << g.countPaths(startVertex, endVertex) << endl;

    return 0;
}
