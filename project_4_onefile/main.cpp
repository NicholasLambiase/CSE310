#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node
{
    int val;
    struct Node *parent, *left, *right;
};

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

Node* bst_Search(Node* x, int key)
{
    if (x == nullptr || x->val == key)
        return x;
    
    if (key < x->val)
        return bst_Search(x->left, key);
    else
        return bst_Search(x->right, key);
}

Node* bst_Insert(Node* &node, int key)
{
    if (node == nullptr)
    {
        Node* newNode = createNode(key);
        return newNode;
    }
    if (key < node->val)
        node->left = bst_Insert(node->left, key);
    else
        node->right = bst_Insert(node->right, key);

    return node;
}

// void bst_Transplant(Node* &root, Node* &u, Node* &v)
// {
//     if(u->parent == nullptr)        //if Node u is the Root Node
//         root = v;
//     else if(u == u->parent->left)   //If Node u is a LEFT Child
//         u->parent->left = v;
//     else                            //if Node u is a RIGHT Child
//         u->parent->right = v;
//     if (v != nullptr)               //if the child is not a nullptr -> update v's parent to u's old parent
//         v->parent = u->parent;
// }

Node* bst_Delete(Node* &node, int key)
{
    if (!node) return node;

        if (key < node->val) {
            node->left = bst_Delete(node->left, key);
        } else if (key > node->val) {
            node->right = bst_Delete(node->right, key);
        } else {
            // Node with only one child or no child
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children, get the inorder successor
            Node* temp = bst_Minimum(node->right);
            node->val = temp->val;
            node->right = bst_Delete(node->right, temp->val);
        }
        return node;
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

        if (node->left != nullptr) NodePtrQueue.push(node->left);
        if (node->right != nullptr) NodePtrQueue.push(node->right);
    }
}




int main(){

    int number_of_queries;
    cin >> number_of_queries;

    Node* root = NULL;

    string command;
    int value;
    
    for (int i = 0; i < number_of_queries; i++)
    {
        cin >> command;
           
        if(command == "INSERT")
        {
            cin >> value;
            root = bst_Insert(root, value);
        }
        else if(command == "DELETE")
        {
            cin >> value;
            root = bst_Delete(root, value);
        }
        else if(command == "SEARCH")
        {
            cin >> value;
            Node* result = bst_Search(root, value);
            cout << (result != nullptr ? "True" : "False") << endl;
        }
        else if(command == "INORDER")
        {
            bst_InOrder(root);
            cout << endl;
        }
        else if(command == "PREORDER")
        {
            bst_PreOrder(root);
            cout << endl;
        }
        else if(command == "POSTORDER")
        {
            bst_PostOrder(root);
            cout << endl;
        }
        else if(command == "LEVELORDER")
        {
            bst_LevelOrder(root);
            cout << endl;
        }
        
    }

    return 0;
}