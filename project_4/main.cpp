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
    
    int querey_count = 0;
    while (querey_count < number_of_queries+1)
    {
        cin >> command;
           
        if(command == "INSERT")
        {
            cin >> value;
            Node* newNode = createNode(value);
            bst_Insert(root, newNode);
        }
        else if(command == "DELETE")
        {
            cin >> value;
            Node* nodeToDelete = bst_Search(root, value);

            if (nodeToDelete != NULL)
                bst_Delete(root, nodeToDelete);
        }
        else if(command == "SEARCH")
        {
            cin >> value;
            Node* result = bst_Search(root, value);
            if (result == NULL)
                cout << "False" << endl;
            else
                cout << "True" << endl;
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
        else if(command == "LEVELORDER"){
            bst_LevelOrder(root);
            cout << endl;
        }
        querey_count++;
    }

    return 0;
}