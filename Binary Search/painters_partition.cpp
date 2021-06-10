/* Question---> Painter's Partition Problem. 
Algorithm---> This is exactly same as page_allocation; the only difference is that the start should begin from the maximum element of the
array because the painters are going to take atleast that much amount of time to complete painting. Rest everything will
remain the same.*/

#include<bits/stdc++.h>
using namespace std;
bool isfeasible(int a[],int n,int m,int min)
{
    int painters=1,sum=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>min)
        return false;
        else if(sum+a[i]>min)
        {
            sum=a[i];
            painters++;
            if(painters>m)
            return false;
        }
        else
            sum+=a[i];
    }
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int maxi=INT_MIN,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        maxi=max(maxi,a[i]);
    }
    int left=maxi,right=sum,ans=INT_MAX;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(isfeasible(a,n,m,mid))
        {
            ans=min(ans,mid);
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}