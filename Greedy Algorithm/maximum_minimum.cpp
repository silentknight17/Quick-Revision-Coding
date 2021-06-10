//Divide the array into two arrays such that the sum of the difference between the elements of first array and second array (i.e., a[i]-b[i]) is once maximum and once minimum.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long mini=0,maxi=0;
    for(int i=0;i<n/2;i++)
    {
       maxi+=(a[i+n/2]-a[i]);
       mini+=(a[2*i+1]-a[2*i]);
    }
    cout<<maxi<<" "<<mini<<endl;
    return 0;

}
