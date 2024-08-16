#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  Node(int val){
      data = val;
      left = right = NULL;
  }
};
void print(std::vector <Node *> const &a) {
   cout << "The path is: : ";

   for(int i=0; i < a.size(); i++)
   cout << a.at(i)->data << ' ';
   return;
}


Node *lca(Node *root, int val1, int val2)
{
//base case and alse handles case 4
if(root==NULL){
    return NULL;
}
//case 1 if it is same as  node 1 or node 2 we simply return the current node as LCA
if(root->data==val1||root->data==val2){
    return root;
}
Node* left_lca=lca(root->left,val1,val2);
Node* right_lca=lca(root->right,val1,val2);

//case 2 if iots left subtree has one node and the right subtree the other , current node is lca
if(left_lca&&right_lca){
    return root;
}

// case 3 if the subtree has both the node then the lca will also be in the same subtree ,check for lca in below subtree

return (left_lca!=NULL)?left_lca:right_lca;


}

int main() {
	
	Node *root=new Node(70);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(50);
	root->left->right=new Node(10);
	root->left->left->left=new Node(60);
	root->left->left->right=new Node(40);
	root->left->left->left->left=new Node(90);
	root->left->left->right->right=new Node(110);
	root->left->right->right=new Node(80);
	root->left->right->right->right=new Node(100);
	

	Node *result = lca(root,90,110);
	cout << "\nLowest Common Ancestor: "<< result->data;
}