class Node:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.data = val


def getKthSmallest(node):

    global count

    if node != None:
        getKthSmallest(node.left)
        count -= 1

        if count == 0:
            print(node.data)
            return

        getKthSmallest(node.right)


# Driver code
root = Node(60)
root.left = Node(50)
root.right = Node(80)
root.left.left = Node(30)
root.left.right = Node(55)
root.right.left = Node(70)
root.right.right = Node(90)
root.right.left.right = Node(75)

count = 3
getKthSmallest(root)