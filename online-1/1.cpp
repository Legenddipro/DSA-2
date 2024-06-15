#include<bits/stdc++.h>
using namespace std;

vector<int> parent(100);
vector<int> size1(100);
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
int main()
{
    for (int i =0;i<100;i++)
    {
        create_set(i);
    }
    int no_vertices,no_edges;
    cin>>no_vertices>>no_edges;
    vector<vector<int>> edges;
    for(int i =0;i<no_edges;i++)
    {
     int u,v,weight;
      cin>>u>>v>>weight;
      edges.push_back({weight,u,v});
    }
    sort(edges.begin(),edges.end());
    for(auto i : edges)
    {
        int weight1  = i[0];
        int p = i[1];
        int q = i[2];
        int x = search_set(p);
        int y = search_set(q);
        if(x == y)
        continue;
        else{
            cout<< p <<" "<<q<<" "<<weight1<<endl;
            make_union(p,q);
        }

    }


}

