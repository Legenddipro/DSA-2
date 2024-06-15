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
//USING DFS
void dfs(vector<vector<int>>& rGraph, int s, vector<bool>& visited,int no_vertices)
{
	visited[s] = true;
	for (int i = 1; i <=no_vertices; i++)
	if (rGraph[s][i] && !visited[i])
		dfs(rGraph, i, visited,no_vertices);
}

vector<vector<int>> ford_fulkerson( int source, int sink,vector<vector<int>>& graph,int& max_flow) {
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
   return residualGraph;
}
void minCut(vector<vector<int>>& graph,vector<vector<int>>& residualGraph,int source,int no_vertices)
{

    vector<bool> visited(no_vertices+1,false);
	
	dfs(residualGraph, source, visited,no_vertices);
    int V = no_vertices+1;
	//  all edges that are from a reachable vertex to
	// non-reachable vertex in the original graph
    cout<<"[{";
    for(int i =1;i<V;i++)
    {
        if(visited[i])
        {
            cout<<i<<",";
        }
    }
     cout<<"},{";
     for(int i =1;i<V;i++)
     {
        if(!visited[i])
        {
            cout<<i<<",";
        }
     }
     cout<<"}]"<<endl;
    /*
	for (int i = 1; i < V; i++)
	for (int j = 1; j < V; j++)
		if (visited[i] && !visited[j] && graph[i][j])
			cout << i << " - " << j << endl;
        */
	//return;
}
/*
void addEdge(vector<vector<int>>& graph,
             int u, int v, int w)
{
    graph[u][v] = w;
}
*/
int main()
{
    int no_vertices,no_edges,max_flow;
    cin>>no_vertices>>no_edges;


    vector<vector<int>> graph(no_vertices+1, vector<int> (no_vertices+1, 0));
    vector<vector<pair<int,int>>> graph1(no_vertices+1);
    for(int i=0;i<no_edges;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        //addEdge(graph,u,v,w);
        graph1[u].push_back({v,w});
        graph[u][v] = w;
    }
    int source,sink;
    cin>>source>>sink;

/*
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 3, 3);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 2, 5, 2);
    addEdge(graph, 3, 4, 6);
    addEdge(graph, 4, 5, 6);
    */
    vector<vector<int>> residualGraph = ford_fulkerson( source, sink, graph,max_flow);
    vector<vector<int>> residualGraph1 = ford_fulkerson( source, sink, graph,max_flow);
    
    //TO TURN RESIDUAL CAPACITY TO CURRENT CAPACITY && CALCULATE THE NODE OF MAX_FLOW
    int max_flow_node,outflow =0 ;
    int max = -1e7;

    for(int i=1;i<=no_vertices;i++)
    {
        outflow = 0;
        if(i!= source && i!= sink)
        {
        for(auto p : graph1[i])
        {
            residualGraph[i][p.first] = p.second - residualGraph[i][p.first];
            outflow += residualGraph[i][p.first];
        }
        if(outflow > max)
        {
            max = outflow;
            max_flow_node = i;
        }
    }
    }
    //cout << "Maximum Flow: " << ford_fulkerson( source, sink, graph) << endl;
    cout<< max_flow_node <<" "<< max<<endl;
    minCut(graph,residualGraph1,source,no_vertices);
    cout<<max_flow;
    return 0;
}