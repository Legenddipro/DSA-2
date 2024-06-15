#include<bits/stdc++.h>
using namespace std;
void init (vector <vector<int>> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
        {
            vec[i][j] = 0;
        }
    }
}
class Knapsack
{
public:
int no_items,capacity;
vector<int> weights;
vector<int> profits;
vector <vector<int>> dp;
Knapsack(int no_items, int capacity)
{
 this->no_items = no_items;
 this->capacity = capacity;
 weights.resize(no_items+1);
 profits.resize(no_items+1);
 dp.resize(no_items+1);
 for(int i=0;i<no_items+1;i++)
 {
    dp[i].resize(capacity+1);
 }
 init(dp);
}
//
int  Solve(int no_items, int capacity)
{
    // if(capacity <= 0 )
    // return 0 ;
    // if(no_items <= 0)
    // return 0 ;
    // // Current item er weight boro capacity theke
    // if(weights[no_items] > capacity)
    // {
    //     dp[no_items][capacity] =  Solve(no_items - 1, capacity);
    // }
    // else{
    //     dp[no_items][capacity] = max(Solve(no_items-1,capacity),Solve(no_items-1,capacity-weights[no_items])+profits[no_items]);
    // }
    
    for(int i = 1;i<=no_items;i++)
    {
        
        for(int j = 1;j<=capacity;j++)
        {
             // Current item er weight boro capacity theke
             if(weights[i] > j)
    {
        dp[i][j] =  dp[i-1][j];
    }
    
        else{
        dp[i][j] = max(dp[i-1][j],dp[i-1][j-weights[i]]+profits[i]);
    
        }
    }
        
    }
     return dp[no_items][capacity];
}
};
int main()
{
    int no_items,capacity;
    cin>>no_items;
    //cout<<endl;
    cin>>capacity;
   // cout<<endl;
    Knapsack knap(no_items,capacity);
    int weigth,profit;
     knap.weights[0] = 0;
        knap.profits[0] = 0;
    for(int i = 0;i<no_items;i++)
    {
        cin>>weigth>>profit;
        knap.weights[i+1] = weigth;
        knap.profits[i+1] = profit;
    }
  int ans =   knap.Solve(no_items,capacity);
  cout<<ans;
}