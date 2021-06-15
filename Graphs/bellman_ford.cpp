//Question---> Bellman Ford Algorithm Code.

#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
        edges.push_back({v,u,w});
    }
    vector<int>dist(n+1,INF);
    int src;
    cin>>src;
    dist[src]=0;
    for(int i=0;i<n-1;i++)
    {
        for(auto j:edges)
        {
            int u=j[0];
            int v=j[1];
            int w=j[2];
            dist[v]=min(dist[v],dist[u]+w);
        }
    }
     
    for(int i=1;i<=n;i++)
    cout<<dist[i]<<" ";

    return 0;
}
