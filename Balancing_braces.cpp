//Program to use stack to find whether the expression is balanced or not for all braces
#include<iostream>
#include<stack>
using namespace std;
bool balance(string s)
{
        stack<char> st;
        char t;
        for(char c:s)
        {
                if(c=='(' || c=='[' || c=='{')
                        st.push(c);
                else if(c==')' || c==']' || c=='}')
                {
                        if(st.empty())
                                return false;
                        else
                        {
                                t = st.top();
                                if((c=='(' && t!=')') || (c=='[' && t!=']') && (c=='{' && t!='}'))
                                        return false;
                                else
                                        st.pop();

                        }
                }
        }
        return st.empty();
}
int main()
{
        bool ans;
        string s;
        cout<<"Enter the expression : ";
        getline(cin,s);
        ans=balance(s);
        if(ans)
                cout<<"The expression is balanced using braces\n";
        else
                cout<<"The expression is not balanced using braces\n";
        return 0;
}
//COMPLETED
