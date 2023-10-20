#include"bst.h"
#include<iostream>
#include<string>
using namespace std;

Node* createNode(int val){
    Node *temp = new Node;
    temp->val = val;
    //*** Check to see if i need to initialize left and right pointer to Null ***
    return temp;
}

void bst_Insert()
{

}

void bst_Delete();

bool bst_Search()
{

}

void bst_InOrder(Node* x)
{
    if (x != NULL)
    {
        bst_InOrder(x->left);
        cout << x->val << " ";
        bst_InOrder(x->right);
    }
}

void bst_PreOrder()
{
    
}

void bst_PostOrder();

void bst_LevelOrder();

