#include<bits/stdc++.h>
using namespace std;
const int INF = 1000;
void bell_man_ford(vector<int>& dist,vector<vector<int>>& edges,int no_vertice,int source)
{
    dist[source] = 0;
    for(int j =0;j<no_vertice-1;j++)
{
   for(int i = 0;i<edges.size();i++)
   {
    int  u= edges[i][0];
    int v = edges[i][1];
    int w = edges[i][2];
    //cout << u <<"->" <<v << "W: " << w << "D[u]:"<<dist[u]<<" D[v]:" << dist[v];
    dist[v] = min(dist[v],w + dist[u]);
   
   }
}
}
int main()
{
    
}