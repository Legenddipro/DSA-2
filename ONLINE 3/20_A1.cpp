#include<bits/stdc++.h>
const int inf = 1e7;
using namespace std;
void floyd(vector<vector<int>>& dist, int no_city)
{
 for(int k = 1;k<=no_city;k++)
 {
    for(int i = 1;i<=no_city;i++)
 {
    for(int j = 1;j<=no_city;j++)
 {
   if(dist[i][k] != inf && dist[k][j] !=inf )
   {
    dist[i][j]= min(dist[i][j],(dist[i][k]+dist[k][j]));
   } 
 }
 }
 }
}
bool is_neg_cycle(vector<vector<int>>& dist, int no_city)
{
 for(int k = 0;k<no_city;k++)
 {
    for(int i = 0;i<no_city;i++)
 {
    for(int j = 0;j<no_city;j++)
 {
   if(dist[i][k] != inf && dist[k][j] !=inf )
   {
    //dist[i][j]= min(dist[i][j],(dist[i][k]+dist[k][j]));
    if((dist[i][j]>(dist[i][k]+dist[k][j])))
    return true;
   } 

 }
 }
 }
 return false;
}
int main()
{
    int no_city,no_road,thres_cost;
    cin>>no_city>>no_road;
    vector<vector<int>> edges;
    for(int i =0 ;i<no_road;i++)
    {
        int u , v, w;
        cin>>u>>v>>w;
    edges.push_back({u,v,w});
    }
   // cin>>thres_cost;
vector<vector<int>> dist(no_city+1,vector<int>(no_city+1,inf));
//PUTTING ALL DIAGONAL VALUE TO 0
int j =1 ;
while(j<=no_city)
{
  dist[j][j]=0;
    j++;
}
// THE DISTANCE MATRIX CREATED
for (auto vect: edges)
{
    dist[vect[0]][vect[1]] = vect[2];
    dist[vect[1]][vect[0]] = vect[2];
}
 floyd(dist,no_city);
 int w1,w2;
 cin>>w1>>w2;
 int source,destination,cost_wall;
 cin>>source>>destination;
 //TO FIND WALL STREET COST
 for (auto vect: edges)
{
    if(vect[0] == w1 && vect[1] == w2)
       cost_wall = vect[2];
   // dist[vect[0]][vect[1]] = vect[2];
    //dist[vect[1]][vect[0]] = vect[2];
}
 if(dist[source][w1]!= inf && dist[destination][w2]!= inf)
 {
    int p = dist[source][w1] + cost_wall + dist[w2][destination];
    int q = dist[source][w2] + cost_wall + dist[w1][destination];
    if(p<q)
    {
        cout<<p;
    }
    else
    cout<<q;
 }
 /*
 if(is_neg_cycle(dist,no_city))

{
  cout<<"yes";
} 
else
cout<<"no";
*/

/*
 vector<int>count(no_city+1,0);
 int min_count = inf;
 //TO STORE THE COUNT OF CITiES
 for(int i = 1;i<=no_city;i++)
 {
    int count1  = 0;
    for(int m =1;m<=no_city;m++)
    {
    if(i!=m)
    {
     if(dist[i][m]<= thres_cost)
     {
        count1++;
     }
    }
    }
    count[i]= count1;
    if(min_count > count1)
    {
         min_count = count1;
    }
 }
 //cout<<min_count<<endl;
  // TO PRINT THE ANSWERS
 // cout<<count[4]<<endl;
  for(int i =1;i<=no_city;i++)
  {
    if(count[i] == min_count)
    {
        cout<<i<<" ";
    }
  }
  */
}