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
  queue<Node*> q;
  stack<Node*>s;
  q.push(root);
  bool left_to_right=true;
  while(!q.empty()){
    int n=q.size();
    for(int i=0;i<n;i++){
      Node* temp=q.front();
      q.pop();
      if(left_to_right)
      cout<<temp->data<<" ";
      else
      s.push(temp);
      if(temp->left!=NULL){
        q.push(temp->left);
      }
      if(temp->right!=NULL){
        q.push(temp->right);
      }
    }
    if(left_to_right==false){
      while(!s.empty()){
        Node*t=s.top();
        cout<<t->data<<" ";
        s.pop();
      }
    }
    left_to_right=!left_to_right;

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