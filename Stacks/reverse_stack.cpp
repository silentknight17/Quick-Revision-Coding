#include<bits/stdc++.h>
using namespace std;


void insertatbottom(stack<int>&s,int &ele)
{
    
    if(s.empty())
    {
        s.push(ele);
        return;
    }
          
          int x=s.top();
          s.pop();
          insertatbottom(s,ele);
          s.push(x);


}


void reverse(stack<int>&s)
{
    
     if(s.empty())
     {
         return;
     }
     
     int x=s.top();
     s.pop();
     reverse(s);
     insertatbottom(s,x);
     

}
int main()
{
    stack<int>s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        s.push(a);
    }



    reverse(s);

    while(!s.empty())
    {
        int x=s.top();
        s.pop();
        cout<<x<<" ";
    }

    return  0;
}