/* Question----> Given a number n, your task is to find the minimum number of numbers which sums to n.
Example
n = 26 = 42 + 32 + 12 {3 numbers}
or 26 = 52 + 12 {2 numbers}
	So the minimum number of numbers required are 2.
Algo-> Recurrence Relation-> f(x) = min{f(x-i*i)+1}   { 1<=i<=√x } */

#include<bits/stdc++.h>
using namespace std;
int dp[100000];
int find(int n)
{
    if(n==1||n==0||n==2||n==3)
    return n;
    if(dp[n]!=INT_MAX)
    return dp[n];
    for(int i=1;i*i<=n;i++)
    {
      dp[n]=min(dp[n],find(n-i*i)+1);
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;

    for(int i=0;i<100000;i++)
    {
        dp[i]=INT_MAX;
    }
    cout<<find(n)<<endl;
    return 0;
}
