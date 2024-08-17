#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right;
  
  Node(int val)
  {
      data = val;
      left = right = NULL;
  }
};


bool search(Node *node, int value){
    
    while(node!=NULL){
        
        // data is present at node
        if(node->data==value)
            return true;
            
        // value is greater than node's data
        else if(node->data<value)
            node=node->right;
            
        // value is smaller than node's data
        else
            node=node->left;
    }
    return false;
} 

int main() {
	
	Node *root=new Node(70);
	root->left=new Node(50);
	root->right=new Node(90);
	root->left->left=new Node(30);
	root->left->right=new Node(60);
	root->right->left=new Node(80);
	root->right->right=new Node(110);
	
	int x=80;
	
	if(search(root,x))
	    cout<<"Present in the Tree";
	else
	    cout<<"Not Present in the Tree";
}