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
    int no_state,no_flights;
    vector<string>states;
    vector<int>lay_times;
    cin>>no_state>>no_flights;
    for(int i=0;i<no_state;i++)
    {
        string st;
        int lay_time;
        cin>>st>>lay_time;
        states.push_back(st);
        lay_times.push_back(lay_time);
    }
    vector<vector<pair<int,int>>> graph(100000);
   for(int i =0;i<no_flights;i++)
   {
    string st1,st2;
    int cost;
    cin>>st1>>st2>>cost;
    int index1,index2;
    index1= find_node(states,st1);
    index2= find_node(states,st2);
    graph[index1].push_back({cost+lay_times[index2],index2});
    graph[index2].push_back({cost+lay_times[index1],index1});
    
   }
   string source,destination;
    cin>>source>>destination;
     int source_index = find_node(states,source);
  int destination_index = find_node(states,destination);
  vector<int>dist(10000,inf);
  dijextra(source_index,graph,dist);
  cout<<dist[destination_index];
}