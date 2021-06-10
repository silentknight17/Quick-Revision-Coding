/* Question ---> Page Allocation Problem.
Example---> pages[]=[12,34,67,90], m(students)=2
Possible allocations---> [12][34,67,90]---> maximum pages=191
[12,34][67,90]---> maximum pages=157
[12,34,67][90]---> maximum pages=113

Now we have to find minimum of maximum so the answer will be 113. This is similar to maximise the minimum only difference
is that here in this question we have to calculate minimum of maximum.

Algorithm--> Binary Search algo will again work here. First we calculate the sum and then the range in which we have to 
apply the binary search would be start=0 and end=sum. And then check if the value we have obtained is minimum or not. */
#include<bits/stdc++.h>
using namespace std;

bool isfeasible(int a[],int n,int m,int min)
{
    int students=1,sum=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>min)
        return false;

        else if(sum+a[i]>min)
        {
            sum=a[i];
            students++;
            if(students>m)
            return false;
        }
        else{
            sum+=a[i];
        }
    }
    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int left=0,right=sum,ans=INT_MAX;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(isfeasible(a,n,m,mid))
        {
            ans=min(ans,mid);
            right=mid-1;
        }
        else
        left=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
