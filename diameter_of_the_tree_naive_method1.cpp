#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node *left, *right;

    Node (int key)
  {
    this->data = key;
    this->left = this->right = nullptr;
  }
};
int height(Node*root){
    if(root==NULL){
        return 0;
    }
    else{
        return (1+max(height(root->left),height(root->right)));
    }
}
int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int pdiam=1+height(root->left)+height(root->right);
    int ldiam=diameter(root->left);
    int rdiam=diameter(root->right);


    return max(pdiam,max(ldiam,rdiam));
}


int main ()
{
  Node *root = new Node (1);
  root->left = new Node (2);
  root->right = new Node (3);
  root->left->left = new Node (4);
  root->left->right = new Node (5);
  root->left->left->left = new Node (7);
  root->left->left->right = new Node (7);
  root->left->left->left->left = new Node (9);
  root->left->right->right = new Node (8);
  root->left->right->right->right = new Node (10);


  int dia=diameter(root);
  cout<<"the diameter if the tree is :"<<dia;

  return 0;
}