//Question ----> LIS
/*Algorithm-> Time Complexity -> O(N^2)
LIS[i] depends upon Lis[k] where 0<k<i-1. Now we can say that if(a[i]>a[k]) then lis[i]=max(lis[i],1+lis[k])*/

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
    int lis[n];
    for(int i=0;i<n;i++)
    lis[i]=1;
int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            lis[i]=max(lis[i],1+lis[j]);
        }
        ans=max(ans,lis[i]);
    }
    cout<<ans<<endl;
    return 0;
}
