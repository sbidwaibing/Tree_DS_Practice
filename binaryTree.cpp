#include <iostream>
using namespace std;

struct Node 
{
    int data; 
    struct Node *left;
    struct Node *right;

    Node(int value){ 
        data = value;
        left = right = NULL;
    }
};

int main(){
    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(5);

    cout<<"root data: "<<root->data<<endl;
    cout<<"left child data: "<<root->left->data<<endl; 
    cout<<"right child data: "<<root->right->data<<endl;
    cout<<"Left-Right child data: "<<root->left->right->data<<endl;

    return 0;
}
