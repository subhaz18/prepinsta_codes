#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  Node(int val){
      data=val;
      left=right=NULL;
  }
};

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);    
    }
}  

void preorder(Node *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);    
    }
}  

void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right); 
        cout<<root->data<<" ";   
    }
}  

int main() {
	
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->right->left=new Node(4);
	root->right->right=new Node(5);
	
	cout << "\nThe Inorder is : ";
	inorder(root);
	cout << "\nThe Postorder is : ";
	postorder(root);
	cout << "\nThe Preorder is : ";
	preorder(root);

}