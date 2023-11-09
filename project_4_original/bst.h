#ifndef BST_H
#define BST_H

using namespace std;

//BST Structs
struct Node
{
    int val;
    struct Node *parent, *left, *right;
};

//Internal Functions
Node* createNode(int val);
Node* bst_Minimum(Node* root);
// void bst_Transplant(Node* &root, Node* &u, Node* &v);

//BST User Functions
Node* bst_Search(Node* x, int key);
Node* bst_Insert(Node* &node, int key);
Node* bst_Delete(Node* &node, int key);
void bst_InOrder(Node* &x);
void bst_PreOrder(Node* &x);
void bst_PostOrder(Node* &x);
void bst_LevelOrder(Node* &x);

#endif