/* Question---> There are N friends numbered from 0 to N-1. You have to choose 2 person such that they are not related to each other.
You are given information in the form of M pairs (X,Y) i.e. there is a link between X and Y.
Find out the number of ways in which 2 persons from different groups can be chosen.

Alogrithm---> Cooneceted Components and a little bit of P&C.*/

#include<bits/stdc++.h>
using namespace std;
vector<bool>visited;
vector<vector<int>>adj;
int get_com(int i)
{
    if(visited[i]==true)
    return 0;

    visited[i]=true;
    int ans=1;
    for(auto j:adj[i])
    {
        if(!visited[j])
        {
            ans+=get_com(j);
            visited[j]=true;
        }
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    adj=vector<vector<int>>(n);
    visited=vector<bool>(n,false);

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>components;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            components.push_back(get_com(i));
        }
    }
    int ans=0;
    for(int i=0;i<components.size();i++)
    {
        ans+=components[i]*(n-components[i]);
    }
    cout<<(ans/2);
    return 0;
    
}