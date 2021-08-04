//Question---> K- Oredered LCS
#include<bits/stdc++.h>
using namespace std;
int dp[205][205][205];
vector<int>a;
vector<int>b;
int lcs(int i,int j,int k,int n,int m)
{
    if(i==n||j==m)
    return 0;
    if(dp[i][j][k]!=-1)
    return dp[i][j][k];

int c1=0,c2=0,c3=0;
    if(a[i]==b[j])
    c1=1+lcs(i+1,j+1,k,n,m);
    if(k>0)
    {
        c2=1+lcs(i+1,j+1,k-1,n,m);
    }
    c3=max(lcs(i+1,j,k,n,m),lcs(i,j+1,k,n,m));
    return dp[i][j][k]=max({c1,c2,c3});
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,m,k;
    cin>>n>>m>>k;
    a=vector<int>(n);
    b=vector<int>(m);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    cin>>b[i];
    
    cout<<lcs(0,0,k,n,m)<<endl;
    return 0;

    
}