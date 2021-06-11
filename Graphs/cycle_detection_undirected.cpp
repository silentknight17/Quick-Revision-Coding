//Question---> Cycle Detection in Undirected graph.
//Algorithm-> DFS and find out whether the back edge exists or not.

#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];

bool dfs(int src,vector<bool>&visited,int parent)
{
   visited[src]=true;

   for(auto i=adj[src].begin();i!=adj[src].end();i++)
   {
       if(*i!=parent)
       {
           if(visited[*i]==true)
           return true;
           if(!visited[*i]&&dfs(*i,visited, src))
           return true;
           
       }
      
   }
   return false;
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
    vector<bool>visited(n,false);
    bool cycle=false;
    for(int i=0;i<n;i++)
    {
        if(!visited[i]==true&&dfs(i,visited,-1))
        cycle=true;
    }
if(cycle==true)
cout<<"Cycle Exists"<<endl;
else
cout<<"Cycle does not exist"<<endl;
return 0;
}