//Question---> Maximum Sum Subarray with sum<X and with a window of k.
// Algorithm---> Typical question of sliding window.

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
    int x, k,sum=0,ans=0;
    cin>>k>>x;
    for(int i=0;i<k;i++)
    {
        sum+=a[i];
    }

    if(sum<x)
    ans=sum;
    
    for(int i=k;i<n;i++)
    {
        sum-=a[i-k];
        sum+=a[i];
        if(sum<x)
        {
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
    return 0;
}