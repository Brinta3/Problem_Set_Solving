#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int vertex = 8, edge = 14;
enum colorname { WHITE, GREY, BLACK };
int color[10], dis_time[10], fin_time[10];
int time;
queue<int> q;

void BFS(vector<int> G[], int s) {
    time = 0;
    q.push(s);
    color[s] = GREY;
    dis_time[s] = ++time;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " --- ";

        for (int v = 0; v < G[u].size(); v++) {
            int adj = G[u][v];
            if (color[adj] == WHITE) {
                color[adj] = GREY;
                dis_time[adj] = ++time;
                q.push(adj);
            }
        }

        color[u] = BLACK;
        fin_time[u] = ++time;
    }
}

void BFS_initialize(vector<int> G[]) {
    for (int u = 0; u < vertex; u++) {
        color[u] = WHITE;
        dis_time[u] = 0;
        fin_time[u] = 0;
    }
    for (int u = 0; u < vertex; u++) {
        if (color[u] == WHITE) {
            BFS(G, u);
        }
    }
}

int main() {
    vector<int> graph[10];

    cout << "Enter each edge (u v):\n";
    for (int u = 0; u < edge; u++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    cout << "\nInput graph adjacency list:\n";
    for (int u = 0; u < vertex; u++) {
        cout << u << " --> ";
        for (int v = 0; v < graph[u].size(); v++) {
            cout << graph[u][v] << "  ";
        }
        cout << endl;
    }

    cout << "\nBFS Traverse:\n";
    BFS_initialize(graph);

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
