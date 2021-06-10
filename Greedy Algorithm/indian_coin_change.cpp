//Greedy ----> Indian Coin Change


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
    int ans=0;
    int x;
    cin>>x;
    sort(a,a+n,greater<int>());
    for(int i=0;i<n;i++)
    {
        ans+=x/a[i];
        x=x-x/a[i]*a[i];
    }
    cout<<ans<<endl;
    return 0;
}