class Node:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.data = val


def searchItem(node, val):
    # Base Cases:
    # node is null or data is present at node
    if node is None or node.data == val:
        return node

    # value is greater than node's data
    if node.data < val:
        return searchItem(node.right, val)

    # value is smaller than node's data
    return searchItem(node.left, val)


# Driver code
root = Node(70)
root.left = Node(50)
root.right = Node(90)
root.left.left = Node(30)
root.left.right = Node(60)
root.right.left = Node(80)
root.right.right = Node(110)

if searchItem(root, 110):
    print("Present in the Tree")
else:
    print("Not Present in the Tree")