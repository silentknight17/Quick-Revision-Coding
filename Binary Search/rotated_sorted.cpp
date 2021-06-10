// Question---> Search in Rotated Sorted Array.  
// Algorithm is simple to find the pivot keeping in mind that a[pivot]<a[next]&& a[pivot]>a[prev]

#include<bits/stdc++.h>
using namespace std;
int binarysearch(int a[],int start,int end, int n,int k)
{
    for(int i=start;i<=end;i++)
    {
        if(a[i]==k)
        return i;
    }
    return -1;
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
    int left=0,right=n-1,ans=-1,middle=-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        int prev=(mid+n-1)%n;
        int next=(mid+1)%n;

        if(a[mid]<=a[next]&&a[mid]<=a[prev])
        {
             middle=mid;
             break;
        }
        else if(a[mid]>=a[left])
        left=mid+1;
        else
        right=mid-1;
}
int x=binarysearch(a,0,middle-1,n,k);
int y=binarysearch(a,middle,n-1,n,k);

if(x!=-1)
{
    cout<<x<<endl;
    return 0;
}
if(y!=-1)
{
    cout<<y<<endl;
    return 0;
}
return 0;
}