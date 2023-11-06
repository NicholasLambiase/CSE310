#include"bst.h"
#include<iostream>
#include<string>
#include<queue>

using namespace std;

Node* createNode(int val){
    Node *temp = new Node;
    temp->val = val;
    temp->parent = temp->left = temp->right = nullptr;
    return temp;
}

Node* bst_Minimum(Node* root){
    Node* x = root;
    while (x->left != NULL)
        x = x->left;
    return x;
}

Node* bst_Maximum(Node* root){
    Node* x = root;
    while (x->right != NULL)
        x = x->right;
    return x;
}

Node* bst_Search(Node* x, int key)
{
    if (x == NULL)
        return x;
    else if (x->val == key)
        return x;
    
    if (key < x->val)
        return bst_Search(x->left, key);
    else
        return bst_Search(x->right, key);
}

void bst_Insert(Node* &root, Node* &z)
{
    Node* x = root;
    Node* newParent = NULL;
    
    while (x != nullptr)
    {
        newParent = x;
        if (z->val < x->val)
            x = x->left;
        else
            x = x->right;
    }

    if (newParent == NULL)
        root = z;
    else if (z->val < newParent->val)
        newParent->left = z;
    else
        newParent->right = z;

    z->parent = newParent;
}

void bst_Transplant(Node* &root, Node* &u, Node* &v)
{
    if(u->parent == nullptr)        //if Node u is the Root Node
        root = v;
    else if(u == u->parent->left)   //If Node u is a LEFT Child
        u->parent->left = v;
    else                            //if Node u is a RIGHT Child
        u->parent->right = v;
    if (v != nullptr)               //if the child is not a nullptr -> update v's parent to u's old parent
        v->parent = u->parent;
}

void bst_Delete(Node* &root, Node* &z)
{
    if ((z->left == nullptr) & (z->right == nullptr))           //if Z has no Children -> simply remove Z and update it's parents child ptr to nullptr
    {
        if (z == root)
            root = nullptr;
        else
        {
            if (z == z->parent->left)
                z->parent->left = nullptr;
            else if (z == z->parent->right)
                z->parent->right = nullptr;
        }
    }
    else if ((z->left != nullptr) & (z->right == nullptr))      //if Z has only one child replace z with its' child
        bst_Transplant(root, z, z->left);
    else if ((z->right != nullptr) & (z->left == nullptr))
        bst_Transplant(root, z, z->right);
    else                                                    //If Z has two children
    {
        Node* y = bst_Minimum(z->right);                    //Find the Successor of Z
        if (y != z->right)
        {
            bst_Transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        bst_Transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
}

void bst_InOrder(Node* &x)
{
    if (x != NULL)
    {
        bst_InOrder(x->left);
        cout << x->val << " ";
        bst_InOrder(x->right);
    }
}

void bst_PreOrder(Node* &x)
{
    if (x != NULL)
    {
        cout << x->val << " ";
        bst_PreOrder(x->left);
        bst_PreOrder(x->right);
    }
}

void bst_PostOrder(Node* &x)
{
    if (x != NULL)
    {
        bst_PostOrder(x->left);
        bst_PostOrder(x->right);
        cout << x->val << " ";
    }
}

void bst_LevelOrder(Node* &x)
{
    if (x == NULL)
        return;
    
    queue<Node*> NodePtrQueue;
    NodePtrQueue.push(x);

    while (NodePtrQueue.empty() == false)
    {
        Node* node = NodePtrQueue.front();
        cout << node->val << " ";
        NodePtrQueue.pop();

        if (node->left != nullptr)
            NodePtrQueue.push(node->left);
        if (node->right != nullptr)
            NodePtrQueue.push(node->right);
    }
}