/* Question--> Redundant Parenthesis
Algorithm--> 1) If we encounter an operator or an opening bracket '(', we push it into the stack.
2) If we encounter a closing bracket ')', we pop from the stack until there is an operator. 
3) Then  we remove the opening bracket also from the stack.
4) If we encounter an opening bracket and then we encounter an opening bracket on top of the stack, then we are 
quite sure that the brackets are redundant.*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stack<char>st;
    int flag=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'|s[i]=='/'||s[i]=='(')
        st.push(s[i]);

        else if(s[i]==')')
        {
            if(st.top()=='(')
            {
                flag=1;
                break;
            }
            while(!st.empty()&&(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/'))
            st.pop();
            
            st.pop(); //Popping the opening bracket from the stack
        }
    }
    if(flag==0)
    cout<<"Non-Redundant"<<endl;
    else
    cout<<"Redundant"<<endl;

    return 0;
}
