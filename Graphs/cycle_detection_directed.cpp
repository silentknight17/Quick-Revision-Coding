//Question-> Cycle detection in a directed graph
//Algorithm-> In this case along with the visited array, we also make a stack and check whether any node present in the stack is pointing to any other element in the stack or not.

#include<bits/stdc++.h>
using namespace std;
bool isCycle(int src,vector<vector<int>>&adj,vector<int>&stack,vector<bool>&visited)
{
    stack[src]=1;
    visited[src]=true;

    for(auto i:adj[src])
    {
        if(!visited[i]&&isCycle(i,adj,stack,visited))
        {
            return true;
        }
        if(stack[i]==1)
        return true;
    }
    stack[src]=0;
    return false;

}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<bool>visited(n,false);
    vector<int> stack(n,0);
    bool cycle=false;
    for(int i=0;i<n;i++)
    {
        if(!visited[i]&&isCycle(i,adj,stack,visited))
        cycle=true;
    }
    if(cycle==true)
    cout<<"Cycle Exists"<<endl;
    else
    cout<<"Cycle does not exists"<<endl;
    return 0;

}