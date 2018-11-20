// Sample driver
// EE 312 Fall 2018
//
// The BST should work for any data type or object.
// Other user created objects must have the << operator overloaded for 
// output.
//

#include <iostream>
#include <fstream>
#include "BST312.h"

using namespace std;

template <typename T>
void print(vector<T> vec){
    for(int i = 0 ; i < vec.size() ; i++){
        cout << vec[i] << endl;;
    }
}

int main() {

    ifstream inFile;
    inFile.open("test.txt");

    BST_312<int> bst;
   
    int s;
    inFile >> s;
    while (inFile) {;
        cout << "inserting ... " << s << endl;
        bst.insertItem(s);
        inFile >> s;
    }

    cout << "postorder traversal is " << endl;
    print(bst.postOrderTraversal());
    cout << endl;

    cout << "preorder traversal is " << endl;
    print(bst.preOrderTraversal());
    cout << endl;

    cout << "inorder traversal is " << endl;
    print(bst.inOrderTraversal());
    cout << endl;

    cout << "Is 14 in the tree?" << endl;
    if(bst.isItemInTree(14)){
        cout << "Yes it is" << endl;
    }else{
        cout << "No it is not" << endl;
    }

    cout << "Remove items 8, 18, 14, 10 " << endl;
    cout << "number of nodes in tree before delete is " << bst.countNodes() << endl;
    s = 8;
    bst.deleteItem(s);
    s = 18;
    bst.deleteItem(s);
    s = 14;
    bst.deleteItem(s);
    s = 10;
    bst.deleteItem(s);
    print(bst.inOrderTraversal());
    cout << endl;
    cout << "number of nodes in tree after delete is " << bst.countNodes() << endl;
    cout << endl;

    cout << "Is 10 in the tree?" << endl;
    if(bst.isItemInTree(10)){
        cout << "Yes it is" << endl;
    }else{
        cout << "No it is not" << endl;
    }

    bst.makeEmpty();
    cout << "number of nodes in tree after making empty is " << bst.countNodes() << endl;

}

