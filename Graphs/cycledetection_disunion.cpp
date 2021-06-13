//Question---> Cycle Detection in a graph using Disjoint Set Union.

#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+6;
vector<int>parent(N);
vector<int>size(N);
void make_set(int i)
{
   parent[i]=i;
   size[i]=1;
}
int find_set(int v)
{
    if(v==parent[v])
    return v;
    return parent[v]=find_set(parent[v]);
}
void union_sets(int x,int y)
{
   x=find_set(x);
   y=find_set(y);
   if(x!=y)
   {
       if(size[x]<size[y])
       {
           swap(x,y);
       }
           parent[y]=x;
           size[x]+=size[y];
       
   }
}
int main()
{
    for(int i=0;i<N;i++)
    {
        make_set(i);
    }
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj;
    for(int i=0;i<m;i++)
    {
       int x,y;
       cin>>x>>y;
       adj.push_back({x,y});
    }
    
    bool cycle=false;
    for(auto i:adj)
    {
        int x=i[0];
        int y=i[1];

        int u=find_set(x);
        int v=find_set(y);
        if(u==v)
        cycle=true;

        else
        union_sets(x,y);
    }

    if(cycle)
    cout<<"Cycle Exists"<<endl;
    else
    cout<<"Cycle does not exist"<<endl;
    return 0;

}