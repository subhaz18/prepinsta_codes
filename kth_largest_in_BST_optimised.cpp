#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right;
  int lCount;
  int rCount;
  
  Node(int k)
  {
      data = k;
      left = right = NULL;
      lCount = 0;
      rCount = 0;
  }
};

Node* insert(Node* root, int x)
{
    if (root == NULL)
        return new Node(x);

    if (x < root->data) {
        root->left = insert(root->left, x);
        root->lCount++;
    }
 
    else if (x > root->data){
        root->right = insert(root->right, x);
        root->rCount++;
    }
    return root;
}

Node* kthLargest(Node* root, int k)
{
    if (root == NULL)
        return NULL;
 
    int count = root->rCount + 1;
    if (count == k)
        return root;
 
    if (count > k)
        return kthLargest(root->right, k);
 
    return kthLargest(root->left, k - count);
}

int main() {
	
	Node* root = NULL;
    int keys[] = {60, 50, 80, 30, 55, 70, 90, 40};
 
    for (int x : keys)
        root = insert(root, x);
 
    int k = 4;
    Node* res = kthLargest(root, k);
    
    cout << res->data;
    
    return 0;
	
}