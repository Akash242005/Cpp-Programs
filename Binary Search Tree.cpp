#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key;
        Node* left;
        Node* right;
};

Node* newnode(int data)
{
    Node* n = new Node();
    n->key = data;
    n->left = NULL;
    n->right = NULL;
    return n;
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
            if(temp->key > nn->key)
            {
                if(temp->left == NULL)
                {
                    temp->left = nn;
                    break;
                }
                else if(temp->left != NULL)
                {
                    q.push(temp->left);
                }
            }
            if(temp->key < nn->key)
            {
                if(temp->right == NULL)
                {
                    temp->right = nn;
                    break;
                }
                else if(temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }
        }
    }
    return root;
}

Node* display(Node* root)
{
    if(root == NULL)
    {
        cout << "NULL" << " ";
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            cout << temp->key << "->";
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
    cout << "NULL" << endl;
    return root;
}

Node* minimum(Node* root)
{
    if(root->left == NULL)
    {
        return root;
    }
    else
    {
        return minimum(root->left);
    }
}

Node* delete_element(int data,Node* root)
{
    if(root == NULL)
    {
        cout << "No elements" << " ";
    }
    else if(data < root->key)
    {
        root->left = delete_element(data,root->left);
    }
    else if(data > root->key)
    {
        root->right = delete_element(data,root->right);
    }
    else
    {
        if(root->right!=NULL && root->left!=NULL)
        {
            Node* temp = root;
            Node* min_node = minimum(temp->right);
            root->key = min_node->key;
            root->right = delete_element(min_node->key,root->right);
        }
        else if(root->right!=NULL)
        {
            root = root->right;
        }
        else if(root->left !=NULL)
        {
            root = root->left;
        }
        else
        {
            root = NULL;
        }
    }
    return root;
}

/*
Node* searching_element(Node* root,int data)
{
    if(root == NULL)
    {
        cout << "Not present" << " ";
    }
    else if(data > root->key)
    {
        root->right = searching_element(root->right,data);
    }
    else if(data < root->key)
    {
        root->left = searching_element(root->left,data);
    }
    else
    {
        cout << "Present" << " ";
    }
    return root;
}*/

Node* searching_element(Node* root,int data)
{
    if(root == NULL)
    {
        cout << "Not present" << " ";
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
                cout << "Found" << endl;
                return root;
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
        cout << "Not found" << endl;
    }
    return root;
}

int main() {
    Node* root = NULL;
    root = insert_element(60,root);
    root = insert_element(56,root);
    root = insert_element(61,root);
    root = insert_element(35,root);
    root = insert_element(82,root);
    root = insert_element(7,root);
    root = insert_element(48,root);
    root = insert_element(66,root);
    root = insert_element(96,root);
    root = display(root);
    root = delete_element(7,root);
    root = display(root);
}
