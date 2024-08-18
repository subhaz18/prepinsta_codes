class Node:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.data = val


def insert(node, val):
    if node is None:
        return Node(val)

    elif node.data < val:
        node.right = insert(node.right, val)
    elif node.data > val:

        node.left = insert(node.left, val)

    return node


# A function to do inorder tree traversal
def calcInorder(root):
    if root:
        # Recurring on left child
        calcInorder(root.left)

        # Printing data of node
        print(root.data, end=" "),

        # Recurring on right child
        calcInorder(root.right)


# Driver code
root = Node(70)
root = insert(root, 50)
root = insert(root, 90)
root = insert(root, 30)
root = insert(root, 60)
root = insert(root, 80)
root = insert(root, 110)

calcInorder(root)