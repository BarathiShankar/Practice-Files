//Program to use stack to convert infix to postfix and hence evaluate it to get the final result ( Static sized stack )
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int prec(char op)//To check the precedence of operator
{
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
}
string intopost(const string& in)//Convert infix to postfix
{       string post;
        stack<char> s;
        for(char c: in)
        {
                if(isdigit(c))
                        post+=c;
                else if(c=='(')
                        s.push(c);
                else if(c==')')
                {
                        while(!s.empty() && s.top()!='(')
                        {
                                post+=s.top();
                                s.pop();
                        }
                        if(!s.empty()) s.pop(); //To pop out '(' braces
                }
                else
                {       while((!s.empty()) && (prec(c) <= prec(s.top())))
                        {
                                post+=s.top();
                                s.pop();
                        }
                s.push(c);
                }
        }
        while(!s.empty())
        {
                post+=s.top();
                s.pop();
        }
        return post;
}
void posteval(const string& post)//Evaluating the postfix expression
{   stack<double> s;
    for (char c : post) 
    {
        if (isdigit(c)) 
        {
            s.push(c - '0'); // convert char digit to int
        } 
        else
        {
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();
            switch (c) 
            {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    cout << "Evaluated result : " << s.top() << endl;
}
int main()
{
        string in,post;
        cout<<"Enter the infix expression : ";
        getline(cin,in);
        post=intopost(in);
        cout<<"Converted postfix : "<<post<<endl;
        posteval(post);
        return 0;
}
//Completed
