/* Question---> Coin Change
Algorithm-> Take the coin or do not take the coin and then solve using recursion and then memoize it.*/

#include<bits/stdc++.h>
using namespace std;
const int N =100000;
vector<vector<int>>dp(N,vector<int>(N,-1));
int solve(vector<int>&arr,int n,int x)
{
    if(x==0)
    return 1;
    if(x<0)
    return 0;
   if(n<=0&&x>0)
   return 0;
   if(dp[n][x]!=-1)
   return dp[n][x];
   dp[n][x]=solve(arr,n,x-arr[n-1])+solve(arr,n-1,x);
   return dp[n][x];
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
       cin>>arr[i];
    }
    
    int x;
    cin>>x;

    cout<<solve(arr,n,x)<<endl;
    return 0;
}