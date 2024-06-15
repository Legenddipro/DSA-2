#include<bits/stdc++.h>
using namespace std;
//USING BFS 
int find_augment_path( vector<int>& parent, vector<vector<int>>& residualGraph, int source, int sink) {
   // fill(parent.begin(), parent.end(), -1);
   for(int i=0;i<parent.size();i++)
   {
    parent[i] = -1;
   }
    int V = residualGraph.size();
    parent[source] = -2;
   // queue<pair<int, int>> q;
    queue<vector<int>> q;
    q.push({source, INT_MAX});

    while (!q.empty()) {
        vector<int> v1 = q.front();
       // int u = q.front().first;
      int  u = v1[0];
       // int capacity = q.front().second;
       int capacity = v1[1];
        q.pop();
        for (int av=1; av <= V; av++) {
            if (u != av && parent[av] == -1 && residualGraph[u][av] != 0) {
                parent[av] = u;
                int min_cap = min(capacity, residualGraph[u][av]);
                if (av == sink)
                    return min_cap;
                q.push({av, min_cap});
            }
        }
    }
    return 0;
}
void ford_fulkerson( int source, int sink,vector<vector<int>>& graph,int& max_flow) {
  //  vector<int> parent(graph.size(), -1);
  vector<int> parent (graph.size());
  for(int i =0;i<graph.size();i++)
  {
    parent[i]= -1;
  }
    vector<vector<int>> residualGraph = graph;
    int min_cap = 0;
     max_flow = 0;
    while(1)
    {
   // while (min_cap = bfs(source, sink, parent, residualGraph)) 
    min_cap = find_augment_path(parent, residualGraph,source, sink);
    if(min_cap == 0)
    {
        break;
    }
    else
    {
        max_flow += min_cap;
        int u = sink;
        while (u != source) {
            int v = parent[u];
            residualGraph[u][v] += min_cap;
            residualGraph[v][u] -= min_cap;
            u = v;
        }
    }
}
   // return max_flow;
  // return residualGraph;
}
int main()
{
    int no_man,no_woman;
    cin>>no_man>>no_woman;
    vector<vector<int>> man_info(no_man+2);
    int h,a,d;
    vector<vector<int>> woman_info(no_man+no_woman+2);
    for(int i = 2;i<=no_man+1;i++)
    {
      cin>>h>>a>>d;
      man_info[i] = {h,a,d};
    }
    
   int i = no_man+2;
   while(i<=(no_man+no_woman+1))
   {
    cin>>h>>a>>d;
    woman_info[i] = {h,a,d};
    i++;
   }
   int max_flow;
   int no_vertices = no_man+no_woman+2;
     vector<vector<int>> graph(no_vertices+1, vector<int> (no_vertices+1, 0));
   //TO CREATE EDGES BETWEEN MAN AND SOURCE
   for(int i = 2;i<=no_man+1;i++)
   {
    graph[1][i] = 1;
   }
   // BETWEEN WOMAN AND SINK
   int sink = no_vertices;
   for(int i = no_man+2;i<=(no_man+no_woman+1);i++)
   {
    graph[i][sink]= 1;
   }
   //EDGES BETWEEN MAN AND WOMAN
   for(int i = 2;i<=no_man+1;i++)
   {
    for(int j = no_man+2;j<=(no_man+no_woman+1);j++)
    {
        //0 height , 1 age, 2 divorce
       int diff_height = abs(man_info[i][0] - woman_info[j][0]);
       int diff_age = abs(man_info[i][1] - woman_info[j][1]);
       int diff_divorce = abs(man_info[i][2] - woman_info[j][2]);
       if(diff_height<= 10 && diff_age<=5 && diff_divorce== 0)
       {
        graph[i][j] = 1;
       }
    }
   }
    ford_fulkerson(1,sink,graph,max_flow);
    cout<<max_flow;
}