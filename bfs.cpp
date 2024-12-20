#include <iostream>
using namespace std;


struct node{
    int data;
    struct node* left;
    struct node* right;
    
    node(int value){
        data = value;
        right = left = NULL;
    }
};

vector <vector<int> > levelOrder(node* root){
    //selected vector due to dynamic size allocation
    vector <vector<int> > ans;
    if(root == NULL) return ans;

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        for(int i=0; i<size; i++){
            node *node = q.front();
            q.pop();

            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);

            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    
    for(int i=0;i<ans.size();i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return ans;
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

    levelOrder(root);
   

    return 0;
}