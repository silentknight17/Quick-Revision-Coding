//Question---> Minimum number of jumps to reach the end.
//Time Complexity ----> O(n^2).
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int dp[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(i<=(j+a[j]))
            {
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}