#include<bits/stdc++.h>
using namespace std;
class Edges1 {
public:
    int u, v, w;
    int* mst_count = new int;
     Edges1()
     {

     }
    Edges1(int u, int v, int w)
    {
      this->u = u;
       this->v = v;
        this->w = w;
        *mst_count = 0;
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
vector<int> parent(100);
vector<int>parent1(100);
vector<int> size1(100);
vector<int> size2(100);
void create_set(int v)
{
 parent[v] = v;
 size1[v] = 1;
}

int search_set(int v)
{
    if(v == parent[v])
    {
        return v;
    }
    return parent[v] = search_set(parent[v]);
}
void make_union(int a,int b)
{
    a = search_set(a);
    b = search_set(b);
    if(a!=b)
    {
        if(size1[a]<size1[b])
        {
            swap(a,b);
        }
        parent[b] = a;
        size1[a]+= size1[b];

    }
}
void clear()
{
    parent.clear();
    size1.clear();
}
bool is_Cycle(vector<vector<int>> & edges)
{
    bool cycle = false;
 int j =0;
    while(j<100)
    {
        create_set(j);
        j++;
    }
    for(auto i : edges)
    {
       // int weight1  = i[0];
        int p = i[0];
        int q = i[1];
        int x = search_set(p);
        int y = search_set(q);
        if(x == y)
      //  continue;
      {
      cycle = true;
      return cycle;
    }
        else{
            //cout<< p <<" "<<q<<" "<<weight1<<endl;
            make_union(p,q);
        }
        

    }
    return cycle;

}
void find_edge(Edges1 &e,vector<Edges1> & set2)
{
  for(int i =0;i<set2.size();i++)
  {
    if(set2[i].u == e.u && set2[i].v == e.v)
    {
        (*set2[i].mst_count)++;
        break;
    }
  }
}
int main()
{
    int i =0;
    while(i<100)
    {
        create_set(i);
        i++;
    }
   /* for (int i =0;i<100;i++)
    {
        create_set(i);
    }
    */
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
    sort(edges.begin(),edges.end());
    
    for (int i =0;i<edges.size();i++)
    {
     int weight1  = edges[i][0];
        int p = edges[i][1];
        int q = edges[i][2];
         int x = search_set(p);
        int y = search_set(q);
        if(x == y)
        continue;
        else{
           // cout<< p <<" "<<q<<" "<<weight1<<endl;
            cost+= weight1;
            make_union(p,q);
        }
    }
//cout<<"cost "<<cost<<endl;
//CLEAR SETS
clear();
//to find subset
 vector<vector<Edges1>>result_subset = subsets(set2);
 vector<vector<Edges1>> filtered_subsets;

 //for filtering subset by V-1 and weight  = cost
 
  for(auto vector1: result_subset)
    {
        //cout<<"new subset"<<endl;
        int n = vector1.size();
        int weight2 = 0;
        
        for(auto edge1 :vector1)
        { 
            weight2 += edge1.w;
            
            //cout<<.u<<" "<<g.v<<" "<<endl;
        }
        if(n == (no_vertices-1) && weight2 == cost)
        {
            filtered_subsets.push_back(vector1);
        }
    }
    vector<vector<int>> edges1;
    // to find cycle in subsets
    vector<vector<Edges1>> ans;
    for(auto vector2: filtered_subsets)
    {
        //we check whether this subset contains cycle or not
       // bool cycle = false;
        for(auto edge2: vector2)
        {
        edges1.push_back({edge2.u,edge2.v});

        }
    if( is_Cycle(edges1) == false)
    {
        ans.push_back(vector2);
    }
  edges1.clear();
  clear();

    }
    //TO PRINT ANS
    int h =0;
    for(int i=0;i<ans.size();i++)
    {
        //cout<<"Mst :"<<h<<endl;
        for(int j =0;j<ans[i].size();j++)
        {
           // cout<<" ["<<edge.u<<", "<<edge.v<<" ,"<<edge.w<<" ]";
           // *ans[i][j].mst_count++;
           find_edge(ans[i][j],set2);
        }
        h++;
        cout<<endl;
    }
   // h = h--;

    for(auto i:set2)
    {
       // cout<<*i.mst_count<<endl;
     if(*i.mst_count == 0)
     {
        cout<<"None"<<endl;
     }
    else if(*i.mst_count == h)
     {
        cout<<"any"<<endl;
     }
     else{
        cout<<"at least one"<<endl;
     }
    }
}

