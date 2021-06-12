//Question---> Find teh no. of connected components in a graph and its size.
//Algortihm----> Viisit the nodes in dfs fashion and if the node is not visited, visite that node and its neighbour recursively.
// Each time an unvisited node is found, a new component will be found.

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<bool>visited;

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

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //Each time a new node is found, it means that we have found a new connected component.

    //Vector to store the size of connected components and the size of the components vector gives us the no. of connected components.
    vector<int>components;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            components.push_back(get_com(i));
        }
    }

    for(int i=0;i<components.size();i++)
    cout<<components[i]<<" ";
    return 0;


}