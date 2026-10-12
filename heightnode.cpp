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
int height(node* root){
    if(root==NULL)
    return 0;


else{
        int lef=height(root->left);
        int righ=height(root->right);
        if(lef>righ)
        return (lef+1);
        else
        return (righ+1);
    }
}
    int main(){

    node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    root -> right -> right = new node(6);
    root -> right -> right -> left = new node(7);

    cout<<" The no. of nodes =" << height(root);
    }