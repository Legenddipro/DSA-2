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
int  find_node(vector<string>&states,string st)
{

    for(int i=0;i<states.size();i++)
    {
        if(states[i]== st)
        {
            return i;
        }
    }
  states.push_back(st);
  return states.size()-1;
}
int main()
{
   vector<string>states;
   int s1,r1,s2,r2;
   cin>>s1>>r1>>s2>>r2;
   vector<vector<pair<int,int>>> graph(100000);
   for(int i =0;i<r1;i++)
   {
    string st1,st2;
    int cost;
    cin>>st1>>st2>>cost;
    int index1,index2;
    index1= find_node(states,st1);
    index2= find_node(states,st2);
    graph[index1].push_back({cost,index2});
    graph[index2].push_back({cost,index1});
    
   }
    for(int i =0;i<r2;i++)
   {
    string st1,st2;
    int cost;
    cin>>st1>>st2>>cost;
    int index1,index2;
    index1= find_node(states,st1);
    index2= find_node(states,st2);
    graph[index1].push_back({cost,index2});
    graph[index2].push_back({cost,index1});
    
   }
   int no_port1,no_port2;
   cin>>no_port1;
   vector<pair<string,int>>ports;
   vector<pair<string,int>>ports2;
    for(int i=0;i<no_port1;i++)
    {
        string st;
        int cost;
        cin>>st>>cost;
        ports.push_back({st,cost});
    }
    cin>>no_port2;
    for(int i=0;i<no_port2;i++)
    {
        string st;
        int cost;
        cin>>st>>cost;
        ports2.push_back({st,cost});
    }
    string source,destination;
    cin>>source>>destination;
    for(int i=0;i<ports.size();i++)
    {
        string st = ports[i].first;
        int index1 = find_node(states,st);
        for(int j= 0;j<ports2.size();j++)
        {
            
                int index2 = find_node(states,ports2[j].first);
                int cost = ports2[j].second + ports[i].second;
                graph[index1].push_back({cost,index2});
            

        }
    }
  int source_index = find_node(states,source);
  int destination_index = find_node(states,destination);
  vector<int>dist(10000,inf);
  dijextra(source_index,graph,dist);
  cout<<dist[destination_index];
}