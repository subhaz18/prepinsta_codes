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


void getKthSmallest(Node *node, int &k){
        if(node!=NULL)
        {
            getKthSmallest(node->left,k);
            k--;
        
        if(k == 0)
        {
                cout<<node->data; 
                return;
                
        }
        else
            getKthSmallest(node->right,k);
    }
}

int main() {
	
	Node *root=new Node(60);
	root->left=new Node(50);
	root->right=new Node(90);
	root->left->left=new Node(30);
	root->left->right=new Node(55);
	root->right->left=new Node(70);
	root->right->right=new Node(90);
	root->right->left->right=new Node(75);

	int k = 3;
	getKthSmallest(root, k);
}