#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

void inOrder(node* root)
{
    if(root == NULL) return;
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(node* root)
{
    if(root == NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root)
{
    if(root == NULL) return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << "InOrder Data Traversal   : ";
    inOrder(root);
    cout << endl;

    cout << "PreOrder Data Traversal  : ";
    preOrder(root);
    cout << endl;

    cout << "PostOrder Data Traversal : ";
    postOrder(root);
    cout << endl;

    cout<<"\n";

    return 0;
}
