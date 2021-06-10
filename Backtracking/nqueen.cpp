#include<bits/stdc++.h>
using namespace std;
bool is_safe(vector<vector<int>>&v,int i,int j)
{
    for(int row=0;row<i;row++)
    {
        if(v[row][j]==1)
        return false;
    }
    int row=i;
    int col=j;
    while(row>=0&&col>=0)
    {
        if(v[row][col]==1)
        return false;
        row--;
        col--;
    }
    
    row=i;
    col=j;
    while(row>=0&&col<v.size())
    {
        if(v[row][col])
        return false;
        row--;
        col++;
    }
    return true;
}
bool nqueen(vector<vector<int>>&v,int i)
{
  if(i>=v.size())
  return true;
  for(int col=0;col<v.size();col++)
  {
      if(is_safe(v,i,col))
      {
          v[i][col]=1;
          if(nqueen(v,i+1))
          return true;
          v[i][col]=0;
      }
      
  }
  return false;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n,0));
    nqueen(v,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}