#ifndef BST_H
#define BST_H

using namespace std;

//BST Structs
struct Node
{
    int val;
    struct Node *left, *right;
};

//Internal Functions
Node* createNode(int val);

//BST User Functions
void bst_Insert();
void bst_Delete();
bool bst_Search();
void bst_InOrder();
void bst_PreOrder();
void bst_PostOrder();
void bst_LevelOrder();

#endif