//Question---> Find lcs in 3 strings.

#include<bits/stdc++.h>
using namespace std;

int dp[205][205][205];

int lcs(string &s1,string &s2, string &s3,int i,int j,int k)
{
    if(i==0||k==0||j==0)
    return 0;

    if(dp[i][j][k]!=-1)
    return dp[i][j][k];

    if(s1[i-1]==s2[j-1]&& s2[j-1]==s3[k-1])
    {
        return dp[i][j][k]=1+lcs(s1,s2,s3,i-1,j-1,k-1);
    }

    int l=lcs(s1,s2,s3,i-1,j,k);
    int r=lcs(s1,s2,s3,i,j-1,k);
    int q=lcs(s1,s2,s3,i,j,k-1);
    return dp[i][j][k]=max(l,max(r,q));
}

int main()
{
   /*for(int i=0;i<1001;i++)
   {
       for(int j=0;j<1001;j++)
       {
           for(int k=0;k<1001;k++)
           dp[i][j][k]=-1;
       }
   }*/
   memset(dp,-1,sizeof(dp));
    string s1,s2,s3;
    cin>>s1>>s2>>s3;

    cout<<lcs(s1,s2,s3,s1.length(),s2.length(),s3.length());

    return 0;
}