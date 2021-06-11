//Question----> Find the maximum number of perfect numbers in a subarray of size k.
// Algorithm---> Solved using sliding window. Approach is self understood after looking at the code. Time Complexity = O(n^(sqrt(n))).

#include<bits/stdc++.h>
using namespace std;

bool isPerfect(int n)
{
    int sum=1;
    for(int i=2;i<sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(i==n/i)
            sum+=i;
            else
            sum+=i+n/i;
        }
    }
    if(sum==n&&n!=1)
    return true;
    return false;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int k;
    cin>>k;

    //Replacing all perfect numbers in the array by 1 and non-perfect numbers by 0.
    for(int i=0;i<n;i++)
    {
        if(isPerfect(a[i]))
        {
           a[i]=1;
        }
        else
        a[i]=0;
    }

    
    int ans=0,sum=0;
    for(int i=0;i<k;i++)
    {
       sum+=a[i];
    }
    ans=sum;

    for(int i=k;i<n;i++)
    {
        sum=sum+a[i]-a[i-k];
        ans=max(sum,ans);
    }
    cout<<ans<<endl;
    return 0;
}