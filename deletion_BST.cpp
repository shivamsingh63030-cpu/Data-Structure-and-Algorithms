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

void inorder(node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);
}

node* search(node* root, int val)
{
    if (root == NULL)
        return root;

    if( root -> data == val)
        return root;
    if (val < root->data)    
        return search(root->left, val);

    return search(root->right, val);
    return root;
    
}

node* findMin(node* root){
    while(root -> left != NULL){
        root = root -> left;
    }
    return root;
}

node* deleteNode( node*  root, int key){
    if( root == NULL){
      return NULL;
    }

    if( key < root -> data){
        root -> left = deleteNode(root -> left , key);
    }

    else if ( key > root -> data){
        root -> right = deleteNode(root -> right , key);
    }

    else{
        if( root -> left == NULL){
            node* temp = root -> right;
            delete(root);
            return temp;
        }
    }

    if( root -> right == NULL){
        node* temp = root -> left;
        delete(root);
        return temp;
    }

    node* successor = findMin(root -> right);

    root -> data = successor -> data;
    root -> right = deleteNode( root -> right, successor ->  data);
    return root;
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

    // inorder( root);

    //searching.....
    // int val = 1;
    // node* result = search(root, val);
    // if (result != NULL)
    //     cout << val << " found";
    // else
    //     cout << val << " not found";

//     cout << "\nBefore deletion: ";
// inorder(root);

// root = deleteNode(root, 8);

// cout << "\nAfter deletion: ";
// inorder(root);


    cout << "\nBefore deletion: ";
inorder(root);

root = deleteNode(root, 2);

cout << "\nAfter deletion: ";
inorder(root);
}