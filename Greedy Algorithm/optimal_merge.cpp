//Greedy ---> Optimal_merge.Keep on adding two elements from the array till only one value remains in the array
// Print the cost. Cost here refers to the sum of two elements we are chosing and adding.

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
    sort(a,a+n);
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++)
    {
        pq.push(a[i]);
    }
    int cost=0;
    while(pq.size()>1)
    {
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        int c=a+b;
        pq.push(c);
        cost+=c;
    }
    cout<<cost<<endl;
    return 0;   
}