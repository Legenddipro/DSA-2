#include<bits/stdc++.h>
using namespace std;
const int inf = 1e7;

void dijextra(int source,vector<vector<pair<int,int>>>&graph,vector<int>&dist)//vector<int>&parent)
{
dist[source] =0 ;
multiset<pair<int,int>>s;
s.insert({0,source});
while (s.empty() != true)
{
    auto x = *(s.begin());
   
    s.erase(x);
    for(auto it: graph[x.second])//second means vertex and first means distance
    {
        if(dist[it.second]>dist[x.second]+it.first)
        {
          //  parent[it.second] = x.second;
  s.erase({dist[it.second],it.second});
  dist[it.second] = dist[x.second]+ it.first;
  s.insert({dist[it.second],it.second});
        }

    }
}
}
int main()
{
    int no_city,no_road;
    cin>>no_city>>no_road;
    vector<int>tax(no_city+1);
    for(int i=1;i<=no_city;i++)
    {
        int t;
        cin>>t;
        tax[i] = t;
    }
    vector<vector<pair<int,int>>> graph(100000);
    vector<int>dist(10000,inf);
    for(int i=0;i<no_road;i++)
    {
        int u,v;
        cin>>u>>v;
        int cost = tax[v];
        int cost2 = tax[u];
        graph[u].push_back({cost,v});
        graph[v].push_back({cost2,u});
    }
    dijextra(1,graph,dist);
    cout<<dist[no_city];
}
