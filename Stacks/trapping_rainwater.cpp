/* Question---> Trapping Rainwater
Algo--->    height[]= 0 1 0 2 1 0 1 3 2 1 2 1
            left[](Finding maximum element left of the particular element)
            right[](Finding maximum element right of the particular element)

            Now ans+=max(min(left[i],right[i])-height[i],0)

In case of using a stack, the algo is similar to that of longest area of histogram only difference is we have to
check uptill the height[s.top()]< height[i]---> meaning that we have to store the left element as height[s.top()]
and the right element as height[i] and then we calculate the ans after finding the difference.
Array method--> int trappingWater(int arr[], int n){
        int left[n],right[n],ans=0;
        left[0]=arr[0];
        for(int i=1;i<n;i++)
        left[i]=max(left[i-1],arr[i]);
        
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        right[i]=max(right[i+1],arr[i]);
    
        for(int i=0;i<n;i++)
        {
            int a=min(left[i],right[i]);
            ans+=max(a-arr[i],0);
        }
        return ans;
    }*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    stack<int>s;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        while(!s.empty()&&(a[s.top()]<a[i]))
        {
            int curr=s.top();
            s.pop();
            if(s.empty())
            break;
            else{
                int diff=i-s.top()-1;
                ans+=(min(a[s.top()],a[i])-a[curr])*diff;  
            }
        }
        s.push(i);
    }
    cout<<ans<<endl;
    return 0;
}