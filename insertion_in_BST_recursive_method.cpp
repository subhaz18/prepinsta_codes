#include <bits/stdc++.h>
using namespace std;

class BSTNode
{
    BSTNode *left,*right;
    int data;
    public:
    BSTNode(int val)
    {
        data=val;
        left=right=NULL;
    }

    BSTNode* Insert(BSTNode* root, int value)
    {
    if (!root)
    {
        return new BSTNode(value);
    }

    if (value > root->data)
        root->right = Insert(root->right, value);
    else root->left = Insert(root->left, value);
    return root;
}

    void Inorder(BSTNode* root)
    {
        if (!root) return;
        Inorder(root->left);
        cout << root->data << endl;
        Inorder(root->right);
    }
};

int main()
{
    BSTNode BST(0), *root = NULL;
    root = BST.Insert(root, 70);
    BST.Insert(root, 50);
    BST.Insert(root, 90);
    BST.Insert(root, 30);
    BST.Insert(root, 60);
    BST.Insert(root, 80);
    BST.Insert(root, 110);
 
    BST.Inorder(root);
    return 0;
}