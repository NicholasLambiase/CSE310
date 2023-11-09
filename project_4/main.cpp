#include "bst.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <array>
#include <string>


using namespace std;

int main(){

    int number_of_queries;
    cin >> number_of_queries;

    vector<int> outputArray[10000];

    Node* root = nullptr;

    string command;
    int value;
    
    for (int quereyNumber = 0; quereyNumber < number_of_queries; quereyNumber++)
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
            else
                outputArray[quereyNumber].push_back(3);
        }
        else if(command == "SEARCH")                        //PrintOut code = 1, False = 0, True = 1
        {
            cin >> value;
            Node* result = bst_Search(root, value);
            vector<int> searchResult;
            searchResult.push_back(1);

            if (result == NULL)
                searchResult.push_back(0);
            else
                searchResult.push_back(1);

            outputArray[quereyNumber] = searchResult;
        }
        else if(command == "INORDER")                       //PrintOut code = 2
        {
            vector<int> inOrderResult;
            inOrderResult.push_back(2);
            bst_InOrder(root, inOrderResult);
            outputArray[quereyNumber] = inOrderResult;
        }
        else if(command == "PREORDER")                      //PrintOut code = 2
        {
            vector<int> preOrderResult;
            preOrderResult.push_back(2);
            bst_PreOrder(root, preOrderResult);
            outputArray[quereyNumber] = preOrderResult;
        }
        else if(command == "POSTORDER")                     //PrintOut code = 2
        {
            vector<int> postOrderResult;
            postOrderResult.push_back(2);
            bst_PostOrder(root, postOrderResult);
            outputArray[quereyNumber] = postOrderResult;
        }
        else if(command == "LEVELORDER")                    //PrintOut code = 2
        {
            vector<int> levelOrderResult;
            levelOrderResult.push_back(2);
            bst_LevelOrder(root, levelOrderResult);
            outputArray[quereyNumber] = levelOrderResult;
        }
    }

    for (int quereyNum = 0; quereyNum < number_of_queries; quereyNum++)
    {
        if (!outputArray[quereyNum].empty())
        {
            //Iterator setup
            auto vecIt = outputArray[quereyNum].begin();
            
            // //Debugging
            // cout << "Query Number: " << quereyNum << endl;
            // cout << "Query Code: " << *vecIt << endl;

            switch (*vecIt)
            {
            case 1:                             //Case one is a Search Result
                // //Debugging
                // cout << "Case 1 was entered" << endl;
                
                if (outputArray[quereyNum][1] == 0)
                    cout << "False" << endl;
                else
                    cout << "True" << endl;

                break;
            case 2:                             //Case 2 is a Tree traversal
                // //Debugging
                // cout << "Case 2 was entered" << endl;

                for (vecIt = vecIt+1; vecIt != outputArray[quereyNum].end(); vecIt++)
                    cout << *vecIt << " ";
                cout << endl;
                
                break;
            case 3:                             //Case 3 is a failed Delete
                cout << endl;
            default:
                break;
            }
        }
    }

    return 0;
}