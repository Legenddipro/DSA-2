#include<bits/stdc++.h>
using namespace std;
class Edges1 {
public:
    int u, v, w;
     Edges1()
     {

     }
    Edges1(int u, int v, int w)
    {
      this->u = u;
       this->v = v;
        this->w = w;
    }
};
vector<vector<Edges1>>  subsets(vector<Edges1> & set1)
{
   vector<vector<Edges1>> result;
   vector<Edges1>curr;
   result.push_back(curr);
   for(auto i:set1)
   {
    int n = result.size();
    for(int j = 0;j<n;j++)
    {
        vector<Edges1> temp = result[j];
        temp.push_back(i);
        result.push_back(temp);
    }
   }
  return result;
}
int main()
{
 int no_vertices,no_edges,cost=0;
    cin>>no_vertices>>no_edges;
    vector<vector<int>> edges;
    vector<Edges1> set2;
    for(int i =0;i<no_edges;i++)
    {
     int u,v,weight;
      cin>>u>>v>>weight;
      Edges1 e(u,v,weight);
       set2.push_back(e);
      edges.push_back({weight,u,v});
    }
    vector<vector<Edges1>>result_subset = subsets(set2);
    for(auto k: result_subset)
    {
        cout<<"new subset"<<endl;
        for(auto g :k)
        {
            cout<<g.u<<" "<<g.v<<" "<<endl;
        }
    }

}