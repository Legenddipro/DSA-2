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
    int no_vertice,no_edge;
    vector<vector<int>>edges;
    cin>>no_vertice>>no_edge;
    int i =0 ;
    while(i<no_edge)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
        i++;
    }
    int a,b;
    cin>>a>>b;
    int l,h;
    cin>>l>>h;

  int source,destination;
  cin>>source>>destination;
  vector<int>dist(no_vertice+1,INF);
  bell_man_ford(dist,edges,no_vertice,source);
  vector<int>dist1(no_vertice+1,INF);
  bell_man_ford(dist1,edges,no_vertice,b);
  int x,flag = 0;
  x = -dist1[a];
  //cout<<"dist a  "<<dist1[a]<<endl;
  if(dist1[a] >= INF || x < l)
  {
 x= l;
flag = 1;
  }
  else if(x >= l && x<=h)
  {
   flag =1;
   x = -dist1[a];
  }
  //cout<<flag<<endl;
  if(flag == 0)
  {
    cout<<"impossible"<<endl;
  }
  
  else{
    int inf = 1e9;
  vector<int> dist2(no_vertice+1,inf);
edges.push_back({a,b,x});


bell_man_ford(dist2,edges,no_vertice,source);

if(dist[destination]> dist2[destination])
{
  cout<<x<<" "<<dist2[destination];
}
else{
  cout<<"impossible";
}
  }
 /*
  for(auto i: dist)
  {
    cout<<i<<" ";
  }
*/

}