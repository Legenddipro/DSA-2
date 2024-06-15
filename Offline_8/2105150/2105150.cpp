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
vector<int> indices;
int max_profit;
int used_weight;
Knapsack(int no_items, int capacity)
{
 this->no_items = no_items;
 this->capacity = capacity;
 weights.resize(no_items+1);
 profits.resize(no_items+1);
 indices.resize(no_items+1);
}
//
int  Solve(int no_items, int capacity)
{
   // dp.resize(no_items+1);
   for(int i = 0;i<=no_items;i++)
   {
    dp.push_back(vector<int>(max_profit*no_items+1));
   }
    // for(int i = 0;i<dp.size();i++)
    // {
    //     dp[i].resize(max_profit*no_items+1);
    // }
   // init(dp);
    for(int i = 0;i<dp.size();i++ )
    {
        for(int j = 0;j<=max_profit*no_items;j++)
        {
            if(j <= 0)
            {
                dp[i][j] = 0;
            }
            else if(i == 0 && j>0)
            {
              dp[i][j] = INT_MAX/3;
           //  dp[i][j] = 1e7;
            }
            else{
              //  cout<<j-profits[i]<<"..............."<<endl;
              int idx = j - profits[i];
              idx = idx < 0 ? 0 : idx;
                dp[i][j] = min(dp[i-1][j],weights[i]+dp[i-1][idx]);
                // if((weights[i]+dp[i-1][j-profits[i]]) < dp[i-1][j])
                // {
                //     indices.push_back(i);
                // }
            }
        }
    }
    //to return ans
    // to traverse right to left to find ans 
    for(int i = max_profit*no_items;i>=0;i--)
    {
        if(dp[no_items][i] <= capacity)
        {
           // return dp[no_items][i];
           used_weight = dp[no_items][i];
           return i;
        }
    }
}
void backtrack(int row,int column)
{
    //item taken
    // if(dp[row][column] != dp[row-1][column])
    // {
    //     if(row !=0)
    //     {
    //     indices.push_back(row);
    //     backtrack(row-1,column-profits[column]);
    // }
    // }
    // //item do not take
    // else{
    //     backtrack(row-1,column);
    // }
    int i = row;
    while(i>0)
    {
        //take item
        if(dp[i][column] != dp[i-1][column])
        {
            indices.push_back(i);
            column = column - profits[i];
            i--;
            
        }
        else{
            i--;
        }
    }
}
};
void fill(Knapsack & k1,Knapsack & k2,float theta)
{
    int max = 0;
    for(int i =0 ;i<k1.weights.size();i++)
    {
        k2.weights[i] = k1.weights[i];
        k2.profits[i] = ceil(k1.profits[i]/theta);
        if(k2.profits[i] > max)
        {
            max = k2.profits[i];
        }
    }
    k2.max_profit = max;
}
int main()
{
    int no_items,capacity;
    cin>>no_items;
    //cout<<endl;
    cin>>capacity;
   // cout<<endl;
    vector<float>eps(4);
    int e;
    // for(int j = 0;j<4;j++)
    // {
    //     cin>>e;
    //     eps.push_back(e);
    // }
    eps[0] = 0.5;
    eps[1]= 0.2;
    eps[2] = 0.1;
    eps[3] = 0.01;
    Knapsack knap(no_items,capacity);
    Knapsack knap2(no_items,capacity);
    Knapsack knap3(no_items,capacity);
    Knapsack knap4(no_items,capacity);
    Knapsack knap5(no_items,capacity);
    int weight,profit;
     knap.weights[0] = 0;
        knap.profits[0] = 0;
        knap2.weights[0] = 0;
        knap2.profits[0] = 0;
        knap3.weights[0] = 0;
        knap3.profits[0] = 0;
        knap4.weights[0] = 0;
        knap4.profits[0] = 0;
        knap5.weights[0] = 0;
        knap5.profits[0] = 0;
        int max_profit = 0;
        
        //static int i =1;
        int j = 1;
    for(int i = 0;i<no_items;i++)
    {
        cin>>profit>>weight;
        //profit -= 700;
        knap.weights[i+1] = weight;
        knap.profits[i+1] = profit;

        // knap2.weights[i+1] = weight;
        // knap2.profits[i+1] = profit;

        if(weight > max_profit)
        {
            max_profit = weight;
        }
      //  cout<<profit<<weight<<"................................."<<j<<endl;
        //j++;
    }
    knap.max_profit = max_profit;
    float theta = eps[0]*max_profit/(2*no_items);
      int ans =   knap.Solve(no_items,capacity);
  cout<<"max profit "<<ans<<endl;
  cout<<"used weight "<<knap.used_weight<<endl;
  knap.backtrack(knap.no_items,ans);
  //to print indices
    cout<<"indices "<<endl;
  for(auto p : knap.indices)
  {
    if(p!=0)
    cout<<p<<" ";
  }
  cout<<endl;
  //input fill
    fill(knap,knap2,theta);
    float theta3 = eps[1]*max_profit/(2*no_items);
    float theta4 = eps[2]*max_profit/(2*no_items);
    float theta5 = eps[3]*max_profit/(2*no_items);
    fill(knap,knap3,theta3);
    fill(knap,knap4,theta4);
    fill(knap,knap5,theta5);
  int ans2 =   knap2.Solve(no_items,capacity);
    cout<<"reduced instance "<<ans2<<endl;
    cout<<"reduced instance multiplied  "<<ans2*theta<<endl;
    knap2.backtrack(knap2.no_items,ans2);
     for(auto p : knap2.indices)
  {
    if(p!=0)
    cout<<p<<" ";
  }
  float rounded_up_2 = 0;
  for(auto p : knap2.indices)
  {
    if(p!=0)
    {
       rounded_up_2 += knap2.profits[p] * theta;
    }
  }
  cout<<"ans for rounded up   "<<rounded_up_2<<endl;
  cout<<"used weight for 2   " << knap2.used_weight<<endl;
  cout<<"ratio  "<< 1.0*rounded_up_2/ans<<endl;

//for ans3.....................................
  int ans3 =   knap3.Solve(no_items,capacity);
    cout<<"reduced instance "<<ans3<<endl;
    cout<<"reduced instance multiplied  "<<ans3*theta3<<endl;
    knap3.backtrack(knap3.no_items,ans3);
     for(auto p : knap3.indices)
  {
    if(p!=0)
    cout<<p<<" ";
  }
  float rounded_up_3 = 0;
  for(auto p : knap3.indices)
  {
    if(p!=0)
    {
       rounded_up_3 += knap3.profits[p] * theta3;
    }
  }
  cout<<"ans for rounded up   "<<rounded_up_3<<endl;
  cout<<"used weight for 3  " << knap3.used_weight<<endl;
  cout<<"ratio  "<< 1.0*rounded_up_3/ans<<endl;

//ans 4.......................................................
  int ans4 =   knap4.Solve(no_items,capacity);
    cout<<"reduced instance "<<ans4<<endl;
    cout<<"reduced instance multiplied  "<<ans4*theta4<<endl;
    knap4.backtrack(knap4.no_items,ans4);
     for(auto p : knap4.indices)
  {
    if(p!=0)
    cout<<p<<" ";
  }
  float rounded_up_4 = 0;
  for(auto p : knap4.indices)
  {
    if(p!=0)
    {
       rounded_up_4 += knap4.profits[p] * theta4;
    }
  }
  cout<<"ans for rounded up   "<<rounded_up_4<<endl;
  cout<<"used weight for 4   " << knap4.used_weight<<endl;
  cout<<"ratio  "<< 1.0*rounded_up_4/ans<<endl;

//for ans 5............
  int ans5 =   knap5.Solve(no_items,capacity);
    cout<<"reduced instance "<<ans5<<endl;
    cout<<"reduced instance multiplied  "<<ans5*theta5<<endl;
    knap5.backtrack(knap5.no_items,ans5);
     for(auto p : knap5.indices)
  {
    if(p!=0)
    cout<<p<<" ";
  }
  float rounded_up_5 = 0;
  for(auto p : knap5.indices)
  {
    if(p!=0)
    {
       rounded_up_5 += knap5.profits[p] * theta5;
    }
  }
  cout<<"ans for rounded up   "<<rounded_up_5<<endl;
  cout<<"used weight for 5   " << knap5.used_weight<<endl;
  cout<<"ratio  "<< 1.0*rounded_up_5/ans<<endl;
}