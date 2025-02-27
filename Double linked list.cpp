#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        Node* prev;
        int key;
        Node* next;
}; 

Node* newnode(int data)
{
    Node* n = new Node();
    n->prev = NULL;
    n->key = data;
    n->next = NULL;
    return n;
}

Node* insert_front(int data,Node* head)
{
    Node* nn = newnode(data);
    if(head==NULL)
    {
        head = nn;
    }
    else
    {
        nn->next = head;
        head->prev = nn;
        head = nn;
    }
    return head;
}

Node* insert_last(int data,Node* head)
{
    Node* nn = newnode(data);
    if(head==NULL)
    {
        head = nn;
    }
    else
    {
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
        nn->prev = temp;
    }
    return head;
}

Node* insert_pos(int data,Node* head,int pos)
{
    Node* nn = newnode(data);
    if(head==NULL)
    {
        head = nn;
    }
    else if(pos==1)
    {
        head = insert_front(data,head);
    }
    else
    {
        Node* temp = head;
        int count = 1;
        while(temp != NULL)
        {
            count++;
            if(count==pos)
            {
                break;
            }
            temp = temp->next;
        }
        if(count==pos)
        {
            Node*temp1 = temp->next;
            temp1->prev = nn;
            nn->next = temp1;
            temp->next = nn;
            nn->prev = temp;
        }
        else
        {
            cout << " Invalid" << " ";
        }
    }
    return head;
}

Node* delete_first(Node* head)
{
    if(head == NULL)
    {
        cout << "No elements" << " ";
    }
    else
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
    }
    return head;
}

Node* delete_last(Node* head)
{
    if(head == NULL)
    {
        cout << "No elements" << " ";
    }
    else if(head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        Node* temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node* temp1 = temp->next;
        temp->next = NULL;
        temp1->prev = NULL;
    }
    return head;
}

Node* delete_pos(Node* head,int pos)
{
    if(head == NULL)
    {
        cout << "delete is not possible" << " ";
    }
    else if(pos==1)
    {
        head = delete_first(head);
    }
    else
    {
        int count = 1;
        Node* temp = head;
        while(temp->next != NULL)
        {
            count++;
            if(count==pos)
            {
                break;
            }
            temp = temp->next;
        }
        if(count==pos)
        {
            if(temp->next->next == NULL)
            {
                head = delete_last(head);
            }
            else
            {
                Node* temp1 = temp->next;
                temp1->next->prev = temp;
                temp->next = temp1->next;
                temp1->next = NULL;
                temp1->prev = NULL;
            }
        }
        else
        {
            cout << "Beyond limit" << " ";
        }
    }
    return head;
}

Node* display(Node* head)
{
    if(head==NULL)
    {
        cout << "No elements" << " ";
    }
    else
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << "NULL" << " ";
    }
    return head;
}

bool search_element(int data,Node* head)
{
    if(head== NULL)
    {
        cout << "No elements" << " ";
    }
    else
    {
        Node* temp = head;
        while(temp != NULL)
        {
            if(temp->key == data)
            {
                return true;
            }
            temp = temp->next;
        }
    }
    return false;
}

int main() {
	Node* head = NULL;
	head = insert_front(30,head);
	head = insert_front(20,head);
	head = insert_front(10,head);
	head = insert_last(110,head);
	head = insert_last(120,head);
	head = insert_last(130,head);
	head = insert_pos(40,head,4);
	head = insert_pos(50,head,5);
	head = insert_pos(60,head,6);
	head = insert_pos(70,head,7);
	head = insert_pos(80,head,8);
	head = insert_pos(90,head,9);
	//head = delete_first(head);
	//head = delete_last(head);
	//head = delete_pos(head,10);
	bool a = search_element(40,head);
	cout << "The element is there or not:" << " " << a << endl;
	head = display(head);
	return 0;
}
