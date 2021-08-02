//Question -> Longest Common Subsequence

//Method 1- Using Tabulation
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();

    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}*/

//Method 2-> Recursion+ Memoization

#include<bits/stdc++.h>
using namespace std;

int dp[10000][10000];

int lcs(string &s1,string &s2,int n,int m)
{
    if(n==0||m==0)
    return 0;

    if(dp[n][m]!=-1)
    return dp[n][m];
 
    if(s1[n-1]==s2[m-1])
    {
        dp[n][m]=1+lcs(s1,s2,n-1,m-1);
    }
    else{
        dp[n][m]=max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
    }
    return dp[n][m];
}
int main()
{
    
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    
    for(int i=0;i<10000;i++)
    {
        for(int j=0;j<10000;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<lcs(s1,s2,n,m);
}
