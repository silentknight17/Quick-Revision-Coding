/* Question ---> Three Sum. We have to find wheteher there exists a triplet in an array whose sum is equal to 
the target.
Algorithm --->
1) Sort the array in increasing order.
2) Now, we will traverse the array and keep one element as fixed, we will use two pointers and try to find out
if the sum of all the three elements make up the target or not. 
3) Similar to Binary Search, we can continue with our work and find the solution to the problem. 
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,target;
    cin>>n>>target;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int flag=0;
    for(int i=0;i<n;i++)
    {
        int lo=i+1,hi=n-1;
        while(lo<hi)
        {
            int sum=a[i]+a[lo]+a[hi];
            if(sum==target)
            {
                flag=1;
                break;
            }
            else if(sum>target)
            hi--;
            else if(sum<target)
            lo++;
        }
    }
    if(flag==1)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;

    return 0;
}
