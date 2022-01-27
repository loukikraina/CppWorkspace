#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*************************************************************

    Following is the Binary Tree node structure **/
    template <typename T>
    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

int recurse(BinaryTreeNode < int > * root){
    if(root==NULL) return 0;
    int csum = 0, rootv = root->data;
    if(root->left) csum += root->left->data;
    if(root->right) csum += root->right->data;
    if( csum < rootv){
        if(root->left) root->left->data = rootv;
    	if(root->right) root->right->data = rootv;
    }
    else{
        root->data = csum;
    }
    int lefts = recurse(root->left);
    int rights = recurse(root->right);
    if(lefts+rights > root->data ) root->data = lefts+rights;
    return root->data;
}
void io(BinaryTreeNode < int > * root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    io(root->left);
    io(root->right);
}

void changeTree(BinaryTreeNode < int > * root) {
    recurse(root);
    io(root);
}  


int main() {
    BinaryTreeNode < int > a(40),b(10),c(20),d(2),e(5),f(30),g(40);
    a.left = &b; a.right = &c;
    b.left = &d; b.right = &e;
    c.left = &f; c.right = &g;
	cout<<"GfG!\n";
	changeTree(&a);
	return 0;
}