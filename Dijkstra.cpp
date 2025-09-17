#include<iostream>
#include<vector>
#include<queue>
#define INF 9999999

using namespace std;

int vertex =5, edge=10;
//Function for calc
void printPath(vector<int>& parent, int node) {
    if (node == -1) return;
    printPath(parent, parent[node]);
    cout << node << " ";
}
//Function for calc


int main()
{
    vector<pair<int,int> > G[vertex]; //G[u].(v,w);
    int u,v,w;
    cout<<"enter each edge"<<endl;
    for(int e=0; e<edge; e++)
    {
        cin>>u>>v>>w;
        G[u].push_back(make_pair (v,w));
    }

    cout<<"\n Input Graph"<<endl;
    for(int u=0; u<vertex; u++)
    {
        cout<<u<<"----";
        for(int v=0; v<G[u].size(); v++)
            cout<<G[u][v].first<<":"<<G[u][v].second<<"\t";
        cout<<endl;
    }

    vector<int> dist(vertex, INF);
    vector<int> parent(vertex, -1);
    vector<bool> visit(vertex, false);

    int src=0;
    dist[src]=0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > Q;
    Q.push(make_pair(dist[src],src)); //distance, node

    while(!Q.empty())
    {
        int u= Q.top().second; //node
        Q.pop();
        visit[u]=true;
        for(int v=0; v<G[u].size(); v++)
        {
            int adjNode=G[u][v].first; //v
            int weight = G[u][v].second; //w

            if(!visit[adjNode] && (dist[adjNode]> dist[u]+weight))
            {
                dist[adjNode]=dist[u]+weight;
                parent[adjNode]=u;
                Q.push(make_pair(dist[adjNode], adjNode));

            } //if

        } //for

    } //while

   cout<<"\nNode:";
   for(int i=0; i<vertex; i++)
    cout<<"N"<<i<<"\t";

   cout<<"\nDist:";
   for(int i=0; i<vertex; i++)
    cout<<dist[i]<<"\t";

    cout<<"\nParent:";
   for(int i=0; i<vertex; i++)
    cout<<parent[i]<<"\t";

//Function for calc
    cout << "\n\nShortest Paths from Source (Node 0):" << endl;
for (int i = 0; i < vertex; i++) {
    cout << "Path to " << i << " (cost = " << dist[i] << "): ";
    if (dist[i] == INF) {
        cout << "No path";
    } else {
        printPath(parent, i);
    }
    cout << endl;
}//Function for calc


    return 0;
}//main

/*0 =s, 1=u, 2=v, 4=y
u v w
0 1 10
0 3 5
1 2 1
1 3 2
2 4 4
3 1 3
3 2 9
3 4 2
4 0 7
4 2 6
*/
