//Question---> Palindromic subarray of size k.
//Algorithm ---> Again similar to maximum sum subarray question. Time Complexity = O(n^2).

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int num)
{
    int temp=num,n=0;
    while(temp>0)
    {
        n=n*10+temp%10;
        temp=temp/10;
    }
    if(num==n)
    return true;

    return false;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    int start=-1, num=0;
    for(int i=0;i<k;i++)
    {
        num=num*10+a[i];
    }
    if(isPalindrome(num))
    {
         start=0;
    }
    for(int i=k;i<n;i++)
    {
        num=(num%(int)pow(10,k-1))*10+a[i];

        if(isPalindrome(num))
        {
        start=i-k+1;
        break;
        }
    }

    if(start==-1)
    cout<<"No Palindromic Subarray"<<endl;

    else{
        for(int i=start;i<start+k;i++)
        cout<<a[i];
    }
    return 0;

}