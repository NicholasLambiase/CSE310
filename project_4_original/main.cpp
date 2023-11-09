#include "bst.h"
#include <iostream>
#include <string>

using namespace std;

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