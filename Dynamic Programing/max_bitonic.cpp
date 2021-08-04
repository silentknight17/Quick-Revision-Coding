//Question---> Find the length of maximum bitonic subsequence in the array.
//Algorithm---> We just have to find lis[i]+lds[i]-1 (since ith element we have taken twice in our calculation).

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    vector<int>lis(n,1);
    vector<int>lds(n,1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                lis[i]=max(lis[i],lis[j]+1);
            }
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(a[i]>a[j])
            {
                lds[i]=max(lds[i],lds[j]+1);
            }
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,lis[i]+lds[i]-1);
    }
    cout<<ans<<endl;
    return 0;
}