#include<bits/stdc++.h>
using namespace std;
const int inf = 1e7;

void dijextra(int source,vector<vector<pair<int,int>>>&graph,vector<int>&dist,int no_state,vector<int>&parent)
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
            parent[it.second] = x.second;
  s.erase({dist[it.second],it.second});
  dist[it.second] = dist[x.second]+ it.first;
  s.insert({dist[it.second],it.second});
        }

    }
}
}
int main()
{
    int no_state,no_roads;
    cin>>no_state>>no_roads;
    vector<vector<pair<int,int>>>roads(no_state+1);
    for(int i =  0;i<no_roads;i++)
{
    int u,v,w;
    cin>>u>>v>>w;
    roads[u].push_back({w,v});
   //graph[u].push_back({w,v});
   // graph[v].push_back({w,u});//for undirected graph
}
int source;
cin>>source;
//vector<int>dist(1000000,inf);
vector<vector<int>>dist1(no_state,vector<int>(no_state,inf));
//vector<int>parent(100000,-1);
vector<vector<int>>parent(no_state);
//dijextra(source,roads,dist);
for(int i = 0;i<no_state;i++)
{
    vector<int>parent1(no_state,-1);
    dijextra(i,roads,dist1[i],no_state,parent1);
    parent[i] = parent1;

}
vector<int>res(no_state,inf);
int min = inf;
int destination;
for(int i =0;i<no_state;i++)
{
    if(i!=source)
    {
        res[i]= dist1[source][i]+ dist1[i][source];
    }
    if(min> res[i])
    {
        min = res[i];
        destination =  i;
    }
}
cout<<min<<endl;
//PARENT PRINT
vector<int> path;
path.push_back(destination);
int temp = destination;
while(parent[source][temp]!= source)
{
    path.push_back(parent[source][temp]);
    temp = parent[source][temp];
}
path.push_back(source);

for(int i = path.size()-1;i>=0;i--)
{
    cout<<path[i]<<" ";
}
//FOR 2ND PATH
vector<int> path1;
path1.push_back(source);
int temp = destination;
while(parent[des][temp]!= source)
{
    path.push_back(parent[source][temp]);
    temp = parent[source][temp];
}
path.push_back(source);

for(int i = path.size()-1;i>=0;i--)
{
    cout<<path[i]<<" ";
}
}