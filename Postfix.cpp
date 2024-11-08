#include <bits/stdc++.h>
using namespace std;

int output(string s)
{
    stack<int> stack;
    for(char c:s)
    {
        int num = c-'0';
        if(num>=0 && num<=9)
        {
            stack.push(num);
        }
        else if( c=='+' || c=='-' || c=='/' || c=='*' || c=='%')
        {
            if(c=='+')
            {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                num1 = num2+num1;
                stack.push(num1);
            }
            else if(c=='-')
            {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                num1 = num2-num1;
                stack.push(num1);
            }
            else if(c=='*')
            {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                num1 = num2*num1;
                stack.push(num1);
            }
            else if(c=='/')
            {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                num1 = num2/num1;
                stack.push(num1);
            }
            else if(c=='%')
            {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                num1 = num2%num1;
                stack.push(num1);
            }
        }
    }
    int ans = stack.top();
    return ans;
}

int main() {
	string s;
	getline(cin,s);
	cout << output(s);
	return 0;
}
