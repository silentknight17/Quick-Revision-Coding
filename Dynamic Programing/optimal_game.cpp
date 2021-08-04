//Question ---> Optimal Game Strategy.  For help see Apni Kaksha Youtube ---> Lecture 35.12

#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve(int a[],int n,int i,int j)
{
   if(i==j)
   return a[i];
   if(i>j)
   return 0;

   if(dp[i][j]!=-1)
   return dp[i][j];


   int l= a[i]+min(solve(a,n,i+2,j),solve(a,n,i+1,j-1));
   int r=a[j]+min(solve(a,n,i+1,j-1),solve(a,n,i,j-2));

   return dp[i][j]=max(l,r);

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
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<solve(a,n,0,n-1);
    return 0;
}