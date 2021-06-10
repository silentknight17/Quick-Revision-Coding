//Question ---> Find a number of size K from a given array such that the number is divisible by 3.
//Algo---> Similar question to maximum sum subarray; just that we have to add an additional condition of divisiblity by 3.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    cin>>a[i];

    int k;
    cin>>k;
    
    int sum=0;
    pair<int,int>ans;
    int flag=0;
    for(int i=0;i<k;i++)
    {
      sum+=a[i];
    }
    if(sum%3==0)
    {
        flag=1;
        ans=make_pair(0,k-1);
    }
    for(int i=k;i<n;i++)
    {
        if(flag)
        break;
        sum=sum+a[i]-a[i-k];

        if(sum%3==0)
        {
            flag=1;
            ans=make_pair(i-k+1,i);
        }
    }

    if(flag==1)
    {
         for(int i=ans.first;i<=ans.second;i++)
         cout<<a[i];
    }

    else
    cout<<"Not found"<<endl;
    
return 0;
}