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
int max_dia=0;
int height_dia(Node* root){
    if(root==NULL){
        return 0;
    }
    int lheight=height_dia(root->left);
    int rheight=height_dia(root->right);

    max_dia=max(max_dia,1+lheight+rheight);


    return 1+max(lheight,rheight);
}


int main ()
{
  Node *root = new Node (1);
  root->left = new Node (2);
  root->right = new Node (3);
  root->left->left = new Node (4);
  root->left->right = new Node (5);
  root->left->left->left = new Node (6);
  root->left->left->right = new Node (7);
  root->left->left->left->left = new Node (9);
  root->left->right->right = new Node (8);
  root->left->right->right->right = new Node (10);


  height_dia(root);
  cout<<"the diameter if the tree is :"<<max_dia;

  return 0;
}