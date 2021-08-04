//Question---> Count Number of Binary Strings. Apni Kaksha---> Lecture 35.14
//Algorithm---> Applying DP we can find the recurrence realtion as : 
// If the string ends at 0-> zero[i]=one[i-1]+zero[i-1]. If the string ends at 1-> one[i]=zero[i-1].
//If we carefully see, we can note that this is the answer we get when we find the fib[n+1].

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int fib[n+2];
    //Only change is in value of fib[0]=1;
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<=n+1;i++)
    fib[i]=fib[i-1]+fib[i-2];

    cout<<fib[n+1]<<endl;
    return 0;
}