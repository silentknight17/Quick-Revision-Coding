//Question---> 0-1 Knapsack
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+2,MOD=1e9+7;
int weight[N];
int value[N];

int dp[N][N];
int find(int n,int w)
{
    if(n<=0)
    return 0;
    if(w<=0)
    return 0;
    if(dp[n][w]!=-1)
    return dp[n][w];
    if(w<weight[n-1])
    dp[n][w]= find(n-1,w);
   else
   dp[n][w]= max(find(n-1,w),find(n-1,w-weight[n-1])+value[n-1]);
   return dp[n][w];
}
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        dp[i][j]=-1;
    }
   int n,w;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>weight[i];
   }
   for(int i=0;i<n;i++)
   cin>>value[i];
   cin>>w;
   cout<<find(n,w)<<endl;
   

   return 0;
}