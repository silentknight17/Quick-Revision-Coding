// Choose and Swap (Under Greedy)--->
/* You are given a string s of lower case english alphabets. You can choose any two characters in the string and replace all the occurences of the first character with the second character and replace all the occurences of the second character with the first character. Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once.
Example 1:
Input:A = "ccad" Output: "aacd"
Explanation: In ccad, we choose ‘a’ and ‘c’ and after doing the replacement operation once we get, aacd and this is the lexicographically smallest string possible. */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int n=a.length();
    int v[26];
    for(int i=0;i<26;i++)
    v[i]=-1;
    for(int i=0;i<n;i++)
    {
        if(v[a[i]-'a']==-1)
        v[a[i]-'a']=i;
    }
     int i=0,j=0;
     for(i=0;i<n;i++)
     {
        int flag=0;
        for(j=0;j<a[i]-'a';j++)
        {
            if(v[a[i]-'a']<v[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        break;
     }
     if(i<a.size())
     {
         char c1=a[i];
         char c2=(char)(j+'a');
         for(int i=0;i<n;i++)
          {
              if(a[i]==c1)
              {
                  a[i]=c2;
              }
              else if(a[i]==c2)
              a[i]=c1;
          }
     }
     cout<<a<<endl;
return 0;
}