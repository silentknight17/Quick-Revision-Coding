#include<bits/stdc++.h>
using namespace std;
void permute(vector<int>&a,int idx,vector<vector<int>>&ans)
{
    if(idx==a.size())
    {
        ans.push_back(a);
        return;
    }
    for(int i=idx;i<a.size();i++)
    {
        swap(a[idx],a[i]);
        permute(a,idx+1,ans);
        swap(a[idx],a[i]);
    }
    

}
int main()
{
    int n;
    cin>>n;
    vector<int>a(n,0);
    for(int i=0;i<n;i++)
    cin>>a[i];
    vector<vector<int>>ans;
    permute(a,0,ans);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
  return 0;
  

}