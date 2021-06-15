//Question---> Capture all the O surrounded by X.
/* Algorithm-> 1) Traverse the 'O' Components around the edges of the grid and change it to '*'.
2) The remaining 'O' components will be surrounded regions that can be captured.
3) Change the '*' back to 'O'.*/

#include<bits/stdc++.h>
using namespace std;
void change(vector<vector<char>>&A,int i,int j,int n,int m)
{
    if(i<0||j<0||i>=n||j>=m ||A[i][j]!='O')
    return;
    A[i][j]='*';
    change(A,i+1,j,n,m);
    change(A,i-1,j,n,m);
    change(A,i,j+1,n,m);
    change(A,i,j-1,n,m);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>A(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>A[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0||i==n-1||j==0||j==m-1)
            {
                if(A[i][j]=='O')
                change(A,i,j,n,m);
            }}}
        
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='O')
            A[i][j]='X';
        }}
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='*')
            A[i][j]='O';
        }}
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
return 0;
}