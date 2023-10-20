#include <iostream>
#include <string>
#include <bst.h>

using namespace std;

int main(){

    int number_of_queries;
    cin >> number_of_queries;

    string command;
    int value;

    int querey_count = 0;
    while (querey_count < number_of_queries)
    {
        cin >> command;
           
        if(command == "INSERT")
        {
            cin >> value;
            //Call Insertion method from BST Class
        }
        else if(command == "DELETE")
        {
            cin >> value;
            //Call DELETE method from BST Class
        }
        else if(command == "SEARCH")
        {
            cin >> value;
            //Call SEARCH method from BST Class
        }
        else if(command == "INORDER"){}
            //Call INORDER method from BST Class
        else if(command == "PREORDER"){}
            //Call INORDER method from BST Class
        else if(command == "LEVELORDER"){}
            //Call LEVELORDER method from BST Class


        querey_count++;
    }

    return 0;
}