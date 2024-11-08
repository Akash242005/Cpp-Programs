#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s)
{
    if(s.length() & 1)
    {
        return false;
    }
    stack<char> stack;
    int i;
    for(i=0;i<s.size();i++)
    {
        char ch = s[i];
        if(ch =='(' || ch=='{' || ch=='[')
        {
            stack.push(ch);
        }
        if(ch ==')' || ch=='}' || ch==']')
        {
            if(stack.empty())
            {
                return false;
            }
            char top = stack.top();
            stack.pop();
            if((top=='(' && ch !=')') || (top=='{' && ch!='}') || (top=='[' && ch!=']'))
            {
                return false;
            }
        }
    }
    return stack.empty();
}

int main() {
	string s = "[({)]";
	if(isBalanced(s))
	{
	    cout << "Valid" << endl;
	}
	else
	{
	    cout << "Invalid" << endl;
	}
}
