/* Question---> Longest non-repeating substring
Sample Test Case--> String="pwwkew";   Output----> 3 (wke)

Algorithm---> 1) Store the frequency array type (used for storing the index) of the alphabets.
2) Now we iterate through the string. If we find out that v[s[i]]>start (Initially start=-1), 
then we make the value of start= v[s[i]].
We update the value of the array with the new value and then find the maximum length.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int start=-1,maxi=INT_MIN;
    vector<int>v(256,-1);
    for(int i=0;i<n;i++)
    {
        if(v[s[i]]>start)
        start=v[s[i]];
        v[s[i]]=i;
        maxi=max(maxi,i-start);
    }
    cout<<maxi<<endl;
    return 0;
}
