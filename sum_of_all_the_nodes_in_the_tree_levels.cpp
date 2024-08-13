#include <bits/stdc++.h>
#include<iostream> 
using namespace std;

struct Node {
	int key;
	struct Node *left;
	struct Node *right;
};


Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
	return (temp);
}


int findsum(Node* root)
{
	
	int sum = 0;
	queue<Node*> q;
	
	q.push(root);
	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();
		sum += temp->key;
		if (temp->left) {
			q.push(temp->left);
		}
		if (temp->right) {
			q.push(temp->right);
		}
	}
	return sum;
}

int main()
{
	
	Node* root = newNode(10);
	root->left = newNode(15);
	root->right = newNode(20);
	root->left->left = newNode(25);
	root->left->right = newNode(30);
	root->right->left = newNode(35);
	root->right->right = newNode(40);
	root->right->left->right = newNode(45);

	cout << "Sum of all elements  is: "
		<< findsum(root);
}

