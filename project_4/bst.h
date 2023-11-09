#ifndef BST_H
#define BST_H
#include <vector>

using namespace std;

struct Node
{
    int val;
    struct Node *parent, *left, *right;
};

//Internal Functions
Node* createNode(int val);
Node* bst_Minimum(Node* root);
Node* bst_Maximum(Node* root);
void bst_Transplant(Node* &root, Node* &u, Node* &v);

//BST User Functions
Node* bst_Search(Node* x, int key);
void bst_Insert(Node* &root, Node* &z);
void bst_Delete(Node* &root, Node* &z);
void bst_InOrder(Node* &x, vector<int> &inOrderResult);
void bst_PreOrder(Node* &x, vector<int> &preOrderResult);
void bst_PostOrder(Node* &x, vector<int> &postOrderResult);
void bst_LevelOrder(Node* &x, vector<int> &levelOrderResult);

#endif