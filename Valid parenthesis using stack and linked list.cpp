#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        char key;
        Node* next;
};

Node* newnode(char data)
{
    Node* n = new Node();
    n->key = data;
    n->next = NULL;
    return n;
}

Node* push(char data,Node* head)
{
    Node* nn = newnode(data);
    if(head == NULL)
    {
        head = nn;
    }
    else
    {
        nn->next = head;
        head = nn;
    }
    return head;
}

char pop(Node* &head)
{
    Node* temp = head;
    char c = temp->key;
    head = head->next;
    temp->next = NULL;
    return c;
}

bool isvalid(string s,Node* head)
{
    if(s[0]==']' || s[0]=='}' || s[0]==')')
    {
        return false;
    }
    else
    {
        for(char c:s)
        {
            if(c=='[' || c=='(' || c=='{')
            {
                head = push(c,head);
            }
            else if(c==']' || c=='}' || c==')')
            {
                char ch = pop(head);
                if((ch=='(' && c!=')') || (ch=='{' && c!='}') || (ch=='[' && c!=']'))
                {
                    return false;
                }
            }
        }
        return true;
    }
}

int main() {
	Node* head = NULL;
	string s;
	cin >> s;
	if(s.size()%2 != 0)
	{
	    cout << "Invlaid";
	}
	else if(isvalid(s,head))
	{
	    cout << "Valid" << endl;
	}
	else
	{
	    cout << "Invalid";
	}
}
