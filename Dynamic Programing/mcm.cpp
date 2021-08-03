//Question-> Matrix Chain Multiplication.
// solve(i,j)= solve(i,k)+solve(k+1,j)+arr[i-1]*arr[k]*arr[j] -> Recurrence Relation

#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000];
int mcm(int arr[],int i,int j)
{
    if(i>=j)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    int mn=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp_ans=mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        mn=min(mn,temp_ans);
    }

    return dp[i][j]=mn;
}
int main()
{ 
    for(int i=0;i<10000;i++)
    {
        for(int j=0;j<10000;j++)
        {
          dp[i][j]=-1;
        }
    }
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<mcm(arr,1,n-1)<<endl;
    return 0;
}