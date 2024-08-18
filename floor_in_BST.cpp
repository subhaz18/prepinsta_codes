#include <bits/stdc++.h>
using namespace std;

/* Structure of each Node in the tree */
struct Node {
    int data;
    Node *left, *right;    
    Node(int key) {
        data = key;
        left = right = NULL;
    }
};

/* This function is used to find floor 
  of a key */
int findFloor(Node* root, int key) {
    if (!root)
        return INT_MAX;

    /* When root iself is floor */
    if (root->data == key)
        return root->data;

    /* If root is greater, floor must lie in left
      subtree if exists */
    if (root->data > key)
        return findFloor(root->left, key);

    /* Else, the floor may lie in right subtree
       or may be equal to the root */
    int floorValue = findFloor(root->right, key);
  
    // If we got a smaller or equal in the right subtree
    return (floorValue <= key) ? floorValue : root->data;
}

/* This function is used to insert new 
  values in BST */
Node* insert(Node* root, int key) {
    if (!root)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Driver code
int main() {
    /* Let us create following BST
            7
           / \
          5  10
         / \ / \
        3  6 8 12 */
    Node* root = NULL;
    root = insert(root, 7);
    insert(root, 10);
    insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 8);
    insert(root, 12);

    // Function call
    cout << findFloor(root, 9) << endl;
    return 0;
}
