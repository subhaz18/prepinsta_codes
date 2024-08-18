#include<bits/stdc++.h>
using namespace std;
 struct Node
 {
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left=right=NULL;
    }
 };

 Node* insert(Node *root,int val){
    Node * newnode= new Node(val);
    Node * temp=root;
    Node * parent = NULL;
    while(temp!=NULL){
        parent=temp;
        if(val< temp->data){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    if(parent==NULL){
        return newnode;
    }
    else if(val<parent->data){
        parent->left=newnode;
    }
    else{
        parent->right=newnode;
    }
    return root;
 }
 void printLevelOrder(Node *root)
{
    if (root == NULL)  return;
        
    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }

}
Node * inordersuccessor(Node * curr){
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;

}

Node * deletenode(Node* root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data>val){
        root->left=deletenode(root->left,val);
    }
    else if(root->data<val){
        root->right=deletenode(root->right,val);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node*temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node* successor=inordersuccessor(root);
            root->data=successor->data;
            root->right=deletenode(root->right,successor->data);
        }
    }
    return root;
}






 int main(){
    Node * root=new Node(70);
    root=insert(root,50);
    root=insert(root,90);
    root=insert(root,80);
    root=insert(root,110);
    root=insert(root,85);
   // root=insert(root,110);
   root=deletenode(root,70);

    printLevelOrder(root);
 }