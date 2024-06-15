#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
void dijextra(int source,vector<vector<pair<int,int>>>&graph,vector<int>&dist)
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
  s.erase({dist[it.second],it.second});
  dist[it.second] = dist[x.second]+ it.first;
  s.insert({dist[it.second],it.second});
        }

    }
}
}
//TO FIND PAIR INDEX IN ALL COMBINE
int find_index(pair<int,int>& p,vector<pair<int,int>> & all_combine)
{
   for(int i = 0;i<all_combine.size();i++)
   {
    if(p.first == all_combine[i].first && p.second == all_combine[i].second)
    {
   return i;
    }
   }
}

int main()
{
int no_vertice,no_edge,capacity;
cin>>no_vertice>>no_edge>>capacity;
vector<int>prices(no_vertice+1);
for(int i=1;i<=no_vertice;i++)
{
    int price;
    cin>>price;
    prices[i]= price;
}

vector<int>dist(1000000,inf);
vector<vector<pair<int,int>>>graph(1000000);
vector<vector<pair<int,int>>>roads(no_vertice+1);

//ROADS CREATE
for(int i =  0;i<no_edge;i++)
{
    int u,v,w;
    cin>>u>>v>>w;
    roads[u].push_back({w,v});
   //graph[u].push_back({w,v});
   // graph[v].push_back({w,u});//for undirected graph
}

int source,destination;
cin>>source>>destination;
vector<pair<int,int>> all_combine;

//dijextra(source,graph,dist);
//CREATING NODES
for (int i =1 ;i<=no_vertice;i++)
{
    for(int j =0 ;j<=capacity;j++)
    {
        all_combine.push_back({i,j});//i means cities
        // j capacitys
    }
}
//CONNECTING GRAPH
//FOR DIFFERENT CITY 
for(int i =0 ;i<all_combine.size();i++)
{
 int city1 = all_combine[i].first;
 int gas1 = all_combine[i].second;
  for(auto j:roads[city1])
  {
    int city2 = j.second;
    //j.first means distance
    
    int gas2 = gas1 - j.first;
    pair<int,int> node2(city2,gas2);
 int index =   find_index(node2,all_combine);
 int weight =0 ;
   graph[i].push_back({weight,index});
  }
    //matrix
}
//FOR SAME CITY
for(int i =0 ;i<all_combine.size();i++)
{
    int city1 = all_combine[i].first;
    int gas1 = all_combine[i].second;

    for(int j = 0;j<all_combine.size();j++)
    {
        int city2 = all_combine[j].first;
    int gas2 = all_combine[j].second;
    if(city1 == city2 && gas2 > gas1)
    {
        int cost = prices[city1]* (gas2 - gas1);
        graph[i].push_back({cost,j});
    }
    }
}
pair<int,int> source_pair(source,0);
pair<int,int> destination_pair(destination,0);
int source_index = find_index(source_pair,all_combine);
int destination_index = find_index(destination_pair,all_combine);
dijextra(source_index,graph,dist);
/*
for (int i =1 ;i<=no_vertice;i++)
{
    for(int j =0 ;j<=capacity;j++)
    {
        matrix.push_back({i,j});//i means
        // j capacitys
    }
}
*/

//OUTPUT SHOW
if(dist[destination_index]<inf)
cout<<dist[destination_index];
else{
cout<<"impossible";
}
/*
for(int i =1 ;i<=no_vertice;i++)
{
    if(dist[i]<inf)
    {
        cout<<dist[i]<<" ";
    }
    else
    {
        cout<<"-1 ";
    }
}
*/
}
