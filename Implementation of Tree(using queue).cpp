#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int key;
        Node* right;
        Node* left;
};

Node* newnode(int data)
{
    Node* n = new Node();
    n->key = data;
    n->right = NULL;
    n->left = NULL;
}

Node* insert_element(int data,Node* root)
{
    Node* nn = newnode(data);
    if(root == NULL)
    {
        root = nn;
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left == NULL)
            {
                temp->left = nn;
                break;
            }
            else if(temp->right == NULL)
            {
                temp->right = nn;
                break;
            }
            else
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
    }
    return root;
}

int find_last(Node* root)
{
    Node* present = NULL;
    if(root == NULL)
    {
        cout << "No elements" <<" ";
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            present = q.front();
            q.pop();
            if(present->left != NULL)
            {
                q.push(present->left);
            }
            if(present->right != NULL)
            {
                q.push(present->right);
            }
        }
    }
    return present->key;
}

Node* delete_last(Node* root)
{
    if(root == NULL)
    {
        cout << "No elements" << " ";
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        Node* prev = NULL;
        while(!q.empty())
        {
            Node* present = q.front();
            if(present->left == NULL)
            {
                prev->right = NULL;
            }
            if(present->right == NULL)
            {
                present->left = NULL;
            }
            if(present->left != NULL)
            {
                q.push(present->left);
            }
            if(present->right != NULL)
            {
                q.push(present->right);
            }
            prev = present;
            q.pop();
        }
    }
    return root;
}

Node* delete_element(int data,Node* root)
{
    if(root == NULL)
    {
        cout << "No elements" << " ";
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* present = q.front();
            q.pop();
            if(present->key == data)
            {
                present->key = find_last(root);
                root = delete_last(root);
            }
            if(present->left != NULL)
            {
                q.push(present->left);
            }
            if(present->right != NULL)
            {
                q.push(present->right);
            }
        }
    }
    return root;
}

Node* display_element(Node* root)
{
    if(root == NULL)
    {
        cout << "No elements in tree" << " ";
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            cout << temp->key << " ";
            q.pop();
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
    cout << endl;
    return root;
}

bool sum_tree(Node* root)
{
    if(root == NULL)
    {
        cout << "No elements" << " ";
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* present = q.front();
            q.pop();
            if(present->left != NULL && present->right != NULL)
            {
                Node* right_element = present->right;
                Node* left_element = present->left;
                int sum = right_element->key + left_element->key;
                if(sum != present->key)
                {
                    return false;
                }
            }
            if(present->left != NULL)
            {
                q.push(present->left);
            }
            if(present->right != NULL)
            {
                q.push(present->right);
            }
        }
    }
    return true;
}


int main() {
    Node* root = NULL;
    root = insert_element(70,root);
    root = insert_element(40,root);
    root = insert_element(30,root);
    root = insert_element(5,root);
    root = insert_element(35,root);
    root = insert_element(20,root);
    root = insert_element(10,root);
    root = display_element(root);
    root = delete_element(10,root);
    root = display_element(root);
    //bool a  = sum_tree(root);
    //cout << a;
	return 0;
}
