//Question ---> BFS in a graph

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;

    int x,y;
    vector<int>adj[n+1];
    vector<bool> visited(n+1,false);

    //Taking the input and storing it in the form of adjacency list.
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // Applying BFS

    queue<int>q;
    q.push(1);
    visited[1]=true;

    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        for(auto i=adj[temp].begin();i!=adj[temp].end();i++)
        {
            if(!visited[*i])
            {
                q.push(*i);
                visited[*i]=true;
            }
        }
    }

    return 0;
}