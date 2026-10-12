#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val){
        data= val;
        left = right = NULL;
    }
};

node* insertNode(node* root, int val)
{
    if (root == NULL)
        return new node(val);
    
    if (val > root->data)
    {
        root->right = insertNode(root->right, val);
    }
    else if (val < root->data)
    {
        root->left = insertNode(root->left, val);
    }
    
    return root;
}
//searching...
bool searchNode(node* root, int key) {
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return searchNode(root->left, key);

    return searchNode(root->right, key);
}

void inorder(node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);
}

int main(){
    node* root = NULL;
    root = insertNode(root , 10);
    insertNode( root , 11);
    insertNode( root , 5);
    insertNode( root , 7);
    insertNode( root , 4);
    insertNode( root , 2);
    insertNode( root , 25);
    insertNode( root , 45);
    insertNode( root , 22);

    inorder( root);
    //searching...
    int key;
    cout << "value to be searched"<<endl;
    cin>>key;

    if (searchNode(root, key))
     cout << "Value found";
    else
     cout << "Value not found";

    return 0;

}