#include<bits/stdc++.h>
using namespace std;
bool is_safe(vector<vector<int>>&v,int i,int j);
bool rat_in_maze(vector<vector<int>>&v,int i,int j, vector<vector<int>>&ans);

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    vector<vector<int>>ans(n,vector<int>(n,0));
    
    if(rat_in_maze(v,0,0,ans))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"-1"<<endl;
    }
    
    return 0;

}
bool is_safe(vector<vector<int>>&v,int i,int j)
{
    if(i<v.size()&&j<v[i].size()&&v[i][j]==1)
    return true;
    
    return false;
}
bool rat_in_maze(vector<vector<int>>&v,int i,int j, vector<vector<int>>&ans)
{
    if(i==v.size()-1&&j==v[i].size()-1)
    {
        ans[i][j]=1;
        return true;
    }
    if(is_safe(v,i,j))
    {
        ans[i][j]=1;
       if(rat_in_maze(v,i+1,j,ans))
       return true;
       if(rat_in_maze(v,i,j+1,ans))
       return true;
       
       ans[i][j]=0;
       return false;
    }
    return false;
}