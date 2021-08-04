//Question---> O-N knapsack

#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve(int weight[],int value[],int n,int w)
{
    if(n==0)
    return 0;
    if(w==0)
    return 0;
    
    if(dp[n][w]!=-1)
    return dp[n][w];
if(w>=weight[n-1])
    
    dp[n][w]=max(solve(weight,value,n,w-weight[n-1])+value[n-1],solve(weight,value,n-1,w));

    return dp[n][w];
}
int main()
{
    for(int i=0;i<1001;i++)
    {
        for(int j=0;j<1001;j++)
        dp[i][j]=-1;
    }
    int n;
    cin>>n;
    int weight[n];
    int value[n];
    int w;
    for(int i=0;i<n;i++)
    cin>>weight[i];

    for(int i=0;i<n;i++)
    cin>>value[i];

    cin>>w;

    cout<<solve(weight,value,n,w)<<endl;
    return 0;


}