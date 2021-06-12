//Question-> Find whether the graph is bipartite or not.
//Algortihm--> Traverse the graph and color the neighbours. If we are not able to properly color, then the graph cannot be bipartite.

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>col;
vector<bool>visited;
bool bi;
void color(int u,int curr)
{
    if(col[u]!=-1&&col[u]!=curr)
    {
        bi=false;
        return;
    }
    col[u]=curr;
    if(visited[u])
    return;

    visited[u]=true;

    for(auto i:adj[u])
    {
       
            color(i,curr xor 1);
      
    }

}
int main()
{
    int n,m;
    cin>>n>>m;
    bi=true;
    adj=vector<vector<int>>(n);
    col=vector<int>(n,-1);
    visited=vector<bool>(n,false);
    for(int i=0;i<m;i++)
    {
      int x,y;
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            color(i,0);
        }
    }
    if(bi)
    cout<<"Bipartite Graph"<<endl;
    else
    cout<<"Not Bipartite Graph"<<endl;
    return 0;
    
}