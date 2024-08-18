// CPP code for finding K-th largest Node using O(1)
// extra memory and reverse Morris traversal.
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

// helper function to create a new Node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->right = temp->left = NULL;
	return temp;
}

Node* KthLargestUsingMorrisTraversal(Node* root, int k)
{
	Node* curr = root;
	Node* Klargest = NULL;

	// count variable to keep count of visited Nodes
	int count = 0;

	while (curr != NULL) {
		// if right child is NULL
		if (curr->right == NULL) {

			// first increment count and check if count = k
			if (++count == k)
				Klargest = curr;

			// otherwise move to the left child
			curr = curr->left;
		}

		else {

			// find inorder successor of current Node
			Node* succ = curr->right;

			while (succ->left != NULL && succ->left != curr)
				succ = succ->left;

			if (succ->left == NULL) {

				// set left child of successor to the
				// current Node
				succ->left = curr;

				// move current to its right
				curr = curr->right;
			}

			// restoring the tree back to original binary
			// search tree removing threaded links
			else {

				succ->left = NULL;

				if (++count == k)
					Klargest = curr;

				// move current to its left child
				curr = curr->left;
			}
		}
	}

	return Klargest;
}

int main()
{
	// Your C++ Code
	/* Constructed binary tree is
		4
		/ \
	2	 7
	/ \ / \
	1 3 6 10 */

	Node* root = newNode(60);
	root->left = newNode(50);
	root->right = newNode(80);
	root->left->left = newNode(30);
	root->left->right = newNode(55);
	root->right->left = newNode(70);
	root->right->right = newNode(90);
    root->left->left->right = newNode(40);

	cout << "Finding K-th largest Node in BST : "
		<< KthLargestUsingMorrisTraversal(root, 4)->data;

	return 0;
}
