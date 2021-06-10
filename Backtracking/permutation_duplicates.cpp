#include<bits/stdc++.h>
using namespace std;
/*void permute(vector<int>&a,int idx,vector<vector<int>>&ans)
{
    if(idx==a.size())
    {
        ans.push_back(a);
        return;
    }
    for(int i=idx;i<a.size();i++)
    {
        if(i!=idx && a[i]==a[idx])
        continue;
        swap(a[idx],a[i]);
        permute(a,idx+1,ans);
      //  swap(a[idx],a[i]);
    }*/
void permute(vector<int> nums, vector<vector<int>> &ans, int idx) {
if (idx == nums.size()) {
ans.push_back(nums);
return ;
}
for (int i = idx; i < nums.size(); i++) {
if(i != idx and nums[i]==nums[idx])
continue;
swap(nums[i], nums[idx]);
permute(nums, ans, idx + 1);
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
    permute(a,ans,0);

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