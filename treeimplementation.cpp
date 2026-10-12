#include <iostream>
using namespace std;

struct node{
    char val;
    node * left;
    node * right;
    node(char data){
        val=data;
        left=right=NULL;
    }
};

int countnode(node*root){
    if(root==NULL)
    return 0;
    return 1+countnode(root->left)+countnode(root->right);

}
    int main()
{
    node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    root -> right -> right = new node(6);
    root -> right -> right -> left = new node(7);

    cout<<" The no. of nodes =" << countnode(root);
}
