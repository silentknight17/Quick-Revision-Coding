//Question ---> DFS traversal of the graph

#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100001];
void dfs(vector<bool>&visited,int node)
{
    //Preorder Printing 
    visited[node]=true;
     cout<<node<<" ";
    //Inorder
    for(auto i=adj[node].begin();i!=adj[node].end();i++)
    {
       if(!visited[*i])
       {
           visited[*i]=true;
           dfs(visited,*i);
       }
    }

    //Postorder Printing
   // cout<<node<<" ";
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool>visited(n+1,false);
    dfs(visited,1);
    return 0;
}