#include <iostream>
#include <vector>
using namespace std;

int vertex = 8, edge = 14;
enum colorname { WHITE, GREY, BLACK };
int color[10];

// DFS visit from a single node
void DFS_visit(vector<int> G[], int u) {
    color[u] = GREY;
    cout << u << " --- ";

    for (int i = 0; i < G[u].size(); i++) {
        int adj = G[u][i];
        if (color[adj] == WHITE) {
            DFS_visit(G, adj);
        }
    }

    color[u] = BLACK;
}

// Initialize DFS for all vertices
void DFS_initialize(vector<int> G[]) {
    for (int i = 0; i < vertex; i++)
        color[i] = WHITE;

    for (int i = 0; i < vertex; i++) {
        if (color[i] == WHITE) {
            DFS_visit(G, i);
        }
    }
}

int main() {
    vector<int> graph[10];

    cout << "Enter each edge (u v):\n";
    for (int i = 0; i < edge; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    cout << "\nInput graph adjacency list:\n";
    for (int i = 0; i < vertex; i++) {
        cout << i << " --> ";
        for (int j = 0; j < graph[i].size(); j++)
            cout << graph[i][j] << "  ";
        cout << endl;
    }

    cout << "\nDFS Traverse:\n";
    DFS_initialize(graph);

    return 0;
}

/*
 u v
 0 1
 0 4
 1 2
 1 3
 2 1
 3 3
 4 0
 4 3
 5 0
 5 2
 5 6
 6 2
 6 7
 7 5
*/
