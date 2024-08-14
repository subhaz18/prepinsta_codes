#include <bits/stdc++.h>
#include<algorithm>
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
queue<Node*> q;
int leftview(Node *node){
    if(node == NULL)
        return 1;
    q.push(node);
    if(node->left!=NULL)
    return leftview(node->left);
    else
    return leftview(node->right);
    
}
void printleftview(){
    while (!q.empty())
    {
        Node *temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
    }
    
}
int main() {
	
	Node *root=new Node(20);
	root->left=new Node(70);
	root->right=new Node(90);
	root->left->left=new Node(30);
	root->left->right=new Node(40);
	root->right->right=new Node(70);
    root->right->right->right=new Node(10);
	leftview(root);
    printleftview();
}