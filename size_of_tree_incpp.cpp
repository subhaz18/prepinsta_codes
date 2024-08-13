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

int calcSize(Node *root){
    
    if(root == NULL)
        return 0;
    else
        return(1 + calcSize(root->left) + calcSize(root->right));
}

int main() {
	
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->right->left=new Node(4);
	root->right->right=new Node(5);
	
    cout << "The size of Tree is : " << calcSize(root);
}