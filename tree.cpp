#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

};
Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data =data;
    newNode-> left=newNode->right =nullprt;
    return newNode;
}

int main(int argc, char const *argv[])
{
    //Level 1
    Node* root =createNode(1);

//*level 2

root -> left=createNode(4);
root->right=createNode(8);

//*Level 3
root -> left->left=createNode(1);
root ->right->right=createNode(3);
root->right->left=createNode(7);

cin.get();
    return 0;
}
