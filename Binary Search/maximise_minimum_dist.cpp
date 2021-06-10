/* Question---> Place Elements to maximise the minimum distance.
Algorithm---> BINARY SEARCH.
1) Sort the array.
2) Pick middle element and search for it's feasibility.
3) If feasible, search the right side of the array for element greater than mid.
4) Else, we have to search the left half of the array to decrease the value of mid and then see again 
because we have to search for the maximum element. */

#include<bits/stdc++.h>
using namespace std;

bool isfeasible(int mid,int a[],int n,int k)
{
    int pos=a[0],elements=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]-pos>=mid)
        {
            pos=a[i];
            elements++;
            if(elements==k)
            return true;

        }
    }
    return false;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    sort(a,a+n);
    int res=-1;
    int left=1,right=a[n-1];

    while(left<right)
    {
        int mid=(left+right)/2;
        if(isfeasible(mid,a,n,k))
        {
            res=max(res,mid);
            left=mid+1;
        }
        else
        right=mid;
    }
    cout<<res<<endl;

    return 0;
}