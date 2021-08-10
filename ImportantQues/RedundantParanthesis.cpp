#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "Enter the string : ";
    cin >> s;
    bool ans = false;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' or s[i] == '-' or s[i] == '/' or s[i] == '*')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.top() == '(')
            {
                ans = true;
            }
            while (st.top() == '+' or st.top() == '-' or st.top() == '/' or st.top() == '*')
            {
                st.pop();
            }
            st.pop();
        }
    }
    cout<<ans ; 
    return 0;
}