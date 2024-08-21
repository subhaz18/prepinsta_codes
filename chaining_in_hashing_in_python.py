def display_hash(hashTable):
    for i in range(len(hashTable)):
        print(i, end=" ")

        for j in hashTable[i]:
            print("-->", end=" ")
            print(j, end=" ")

        print()


HashTable = [[] for _ in range(7)]


def Hashing(keyvalue):
    return keyvalue % len(HashTable)


def insert(Hashtable, value):
    i = value % len(HashTable)
    Hashtable[i].append(value)


def searchItem(hashtable, val):
    index = val % len(HashTable)

    for j in hashtable[index]:
        if j == val:
            print("{0} Present in hashtable".format(val))
            return
    print("{0} Not present in hashtable".format(val))


def deleteItem(hashtable, val):
    index = val % len(HashTable)
    for j in hashtable[index]:
        if j == val:
            hashtable[index].remove(j)
            print("{0} removed from hashtable".format(val))


# Driver Code
insert(HashTable, 3)
insert(HashTable, 8)
insert(HashTable, 5)
insert(HashTable, 1)
insert(HashTable, 10)
insert(HashTable, 6)

searchItem(HashTable, 10)
searchItem(HashTable, 12)

deleteItem(HashTable, 10)
searchItem(HashTable, 10)

display_hash(HashTable)