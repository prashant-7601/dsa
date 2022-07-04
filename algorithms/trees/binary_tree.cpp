#include<bits/stdc++.h>
using namespace std;

struct tree{
    int x;
    int y;
    tree* right;
    tree* left;
    tree* parent;
}tree_node;

struct tree* create_node(int val, int index){
    struct tree* temp = new tree;
    temp->x = val;
    temp->y = index;
    temp->right = NULL;
    temp->left = NULL;
    temp->parent = NULL;
    return temp;
}

void insert_node(struct tree* root, struct tree* node){
    if(node->x < root->x){
        if(root->left == NULL)
            root->left = node;
        else
            insert_node(root->left, node);
    }
    else{
        if(root->right == NULL)
            root->right = node;
        else
            insert_node(root->right, node);
    }
}

void preorder(struct tree *root){
    if(root!=NULL){
        cout<<root->x<<" "<<root->y<<"\n";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct tree *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->x<<" "<<root->y<<"\n";
        inorder(root->right);
    }
}

void postorder(struct tree *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->x<<" "<<root->y<<"\n";
    }
}

int main(){
    struct tree* root = NULL, *temp;
    for(int i=0; i<5; i++){
        int x,y;
        cin>>x>>y;
        temp = create_node(x, y);
        if(root == NULL)
            root = temp;
        else
            insert_node(root, temp);
    }
    cout<<"Preorder: \n";preorder(root);
    cout<<"Inorder: \n";inorder(root);
    cout<<"Postorder: \n";postorder(root);
}
