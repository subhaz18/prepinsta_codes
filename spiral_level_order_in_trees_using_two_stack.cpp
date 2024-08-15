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

void spiralOrderTraversal (Node * root)
{
  if (root == NULL){
    return;
  }
  stack<Node*> s1;
  stack<Node*> s2;
  s1.push(root);
  while(!s1.empty()||!s2.empty()){
    while(!s1.empty()){
        Node* temp= s1.top();
        s1.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
        s2.push(temp->left);
        if(temp->right!=NULL)
        s2.push(temp->right);
    }
    while(!s2.empty()){
        Node* temp= s2.top();
        s2.pop();
        cout<<temp->data<<" ";
        if(temp->right!=NULL)
        s1.push(temp->right);
        if(temp->left!=NULL)
        s1.push(temp->left);
    }
  }

}

int main ()
{
  Node *root = new Node (15);
  root->left = new Node (10);
  root->right = new Node (20);
  root->left->left = new Node (8);
  root->left->right = new Node (12);
  root->right->left = new Node (16);
  root->right->right = new Node (25);

  spiralOrderTraversal (root);

  return 0;
}