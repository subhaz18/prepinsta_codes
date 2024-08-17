class Node:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.data = val


def searchItem(node, val):
    while node is not None:

        if node.data == val:
            return True

        elif node.data < val:
            node = node.right

        else:
            node = node.left
    return False


# Driver code
root = Node(70)
root.left = Node(50)
root.right = Node(90)
root.left.left = Node(30)
root.left.right = Node(60)
root.right.left = Node(80)
root.right.right = Node(110)

if searchItem(root, 80):
    print("Present in the Tree")
else:
    print("Not Present in the Tree")