#include <bits/stdc++.h>
using namespace std;

class BinaryNode 
{
public:
    int key;
    int height;
    BinaryNode *left, *right;
};

BinaryNode* newNode1(int data)
{
    BinaryNode* temp = new BinaryNode();
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}

BinaryNode* display(BinaryNode* root)
{
    if (root == NULL) 
    {
        cout << "Tree Empty" << endl;
        return root;
    }

    queue<BinaryNode*> queue;
    queue.push(root);

    while (!queue.empty()) 
    {
        BinaryNode* front = queue.front();
        queue.pop();
        cout << front->key << " -> ";

        if (front->left != NULL) {
            queue.push(front->left);
        }
        if (front->right != NULL) {
            queue.push(front->right);
        }
    }
    cout << "NULL" << endl;
    return root;
}

int getHeight(BinaryNode* node) 
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

BinaryNode* rotateRight(BinaryNode* disbalancedNode)
{
    BinaryNode* newRoot = disbalancedNode->left;
    disbalancedNode->left = newRoot->right;
    newRoot->right = disbalancedNode;

    disbalancedNode->height = 1 + max(getHeight(disbalancedNode->left), getHeight(disbalancedNode->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

BinaryNode* rotateLeft(BinaryNode* disbalancedNode) 
{
    BinaryNode* newRoot = disbalancedNode->right;
    disbalancedNode->right = newRoot->left;
    newRoot->left = disbalancedNode;

    disbalancedNode->height = 1 + max(getHeight(disbalancedNode->left), getHeight(disbalancedNode->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

int getBalance(BinaryNode* node)
{
    if (node == NULL) 
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

BinaryNode* insert(BinaryNode* node, int key) 
{
    if (node == NULL) 
    {
        return newNode1(key);
    }
    if (key < node->key) 
    {
        node->left = insert(node->left, key);
    } 
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else 
    {
        return node; 
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
    {
        return rotateRight(node);
    }

    if (balance < -1 && key > node->right->key)
    {
        return rotateLeft(node);
    }
    
    if (balance > 1 && key > node->left->key) 
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && key < node->right->key) 
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

BinaryNode* minimum(BinaryNode* root) 
{
    if (root->left == NULL)
    {
        return root;
    } 
    else 
    {
        return minimum(root->left);
    }
}

BinaryNode* deleteNode(BinaryNode* root, int data) 
{
    if (root == NULL) {
        cout << "Value not found in BST";
        return NULL;
    }

    if (data < root->key)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->key)
    {
        root->right = deleteNode(root->right, data);
    } else
    {
        if (root->left != NULL && root->right != NULL)
        {
            BinaryNode* temp = root;
            BinaryNode* minNodeForRight = minimum(temp->right);
            root->key = minNodeForRight->key;
            root->right = deleteNode(root->right, minNodeForRight->key);
        } 
        else if (root->left != NULL) 
        {
            root = root->left;
        }
        else if (root->right != NULL)
        {
            root = root->right;
        } 
        else 
        {
            root = NULL;
        }
    }

    if (root == NULL) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) 
    {
        return rotateRight(root);
    }

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) 
    {
        return rotateLeft(root);
    }

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

Node* search(Node*root,int data)
{
    if(root==NULL)
    {
     cout<< "false";
    }
    else if(data < root->key)
    {
      root->left=search(root->left,data);  
    }
    else if(data > root->key)
    {
        root->right=search(root->right,data);
    }
    else
    {
        cout<<"true";
    }
    return root;
}

int main()
{
    BinaryNode* root = NULL;

    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 30);
    root = insert(root, 35);
    root = display(root);
    root = deleteNode(root,20);
    root = display(root);

    return 0;
}
