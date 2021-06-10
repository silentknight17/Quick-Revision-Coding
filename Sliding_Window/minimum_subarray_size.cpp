//Question---> Minimum subarray size with sum greater than given sum X.
/* Algorithm-> 1) Let variables be ans, start, end and sum.
2) Iterate over the array and stop when we find the sum>x. 
3) Now, we will iterate the start index and subtract it from the sum and see whether the value remains 
greater than X or not. If yes, then replace the value of ans with the new value. */

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
    int x;
    cin>>x;
    int ans=n+1,start=0,end=0,sum=0;
    while(end<n)
    {
        while(sum<=x&&end<n)
        {
           sum+=a[end++];
        }
        while(start<n&&sum>x)
        {
            if(end-start<ans)
            ans=end-start;
            sum-=a[start++];
        }
    }
    if(ans!=n+1)
    cout<<ans<<endl;
    else
    cout<<" No such subarray exists"<<endl;
    return 0;
}