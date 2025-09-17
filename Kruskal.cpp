#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, pair<int, int>> > G;  // Graph edges: weight, (u,v)
vector< pair<int, pair<int, int>> > MST; // MST edges
int vertex = 8, edge = 10;
int* vSet;

// Make set for union
void make_set() {
    vSet = new int[vertex + 1];
    for (int i = 1; i <= vertex; i++)
        vSet[i] = i;
}

// Find set with path compression
int find_set(int u) {
    if (u == vSet[u])
        return u;
    return vSet[u] = find_set(vSet[u]);  // Path compression
}

// Union set parent
void union_set(int u, int v) {
    int set_u = find_set(u);
    int set_v = find_set(v);
    if (set_u != set_v)
        vSet[set_u] = set_v;
}

int main() {
    int u, v, w;
    cout << "Enter edges with weight (u v w):" << endl;
    for (int e = 0; e < edge; e++) {
        cin >> u >> v >> w;
        G.push_back(make_pair(w, make_pair(u, v)));
    }

    // Sort edges by weight
    sort(G.begin(), G.end());

    cout << "\nSorted Edges:" << endl;
    cout << "Edge\t\tWeight" << endl;
    for (int i = 0; i < G.size(); i++) {
        cout << "(" << G[i].second.first << "," << G[i].second.second << "): " << G[i].first << endl;
    }

    make_set();

    int totalCost = 0; // Total MST cost

// Kruskal's MST construction
    for (int i = 0; i < G.size(); i++) {
        int u_loc = find_set(G[i].second.first);
        int v_loc = find_set(G[i].second.second);

        if (u_loc != v_loc) {
            MST.push_back(G[i]);
            totalCost += G[i].first;  //Edge cost+edge cost
            union_set(u_loc, v_loc);
        }
    }

    cout << "\nMinimum Spanning Tree (MST):" << endl;
    for (int i = 0; i < MST.size(); i++) {
        cout << "(" << MST[i].second.first << "," << MST[i].second.second << "): " << MST[i].first << endl;
    }

    cout << "\nTotal cost of MST = " << totalCost << endl;

    return 0;
}


/*
u v w
1 2 6
1 3 12
2 3 5
2 5 14
2 8 8
3 4 9
3 6 7
5 8 3
6 7 15
6 8 10
*/
