#include <bits\stdc++.h>
using namespace std;

struct node {
    int num;
    node* nextptr;
} *stnode; // node constructed

void make(int n);
void printMiddle(struct node* stnode);
void display();

int main() // Main method
{
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;
    make(n);
    cout << "\nLinked list data: \n";
    display();
    printMiddle(stnode);

    return 0;
}

void make(int n) // Function to create a linked list
{
    struct node* frntNode, *tmp;
    int num, i;

    stnode = (struct node*)malloc(sizeof(struct node));
    if (stnode == NULL)
    {
        cout << "Memory cannot be allocated";
    }
    else
    {
        cout << "Enter the data for node 1: ";
        cin >> num;
        stnode->num = num;
        stnode->nextptr = NULL; // Links the address field to NULL
        tmp = stnode;

        for (i = 2; i <= n; i++)
        {
            frntNode = (struct node*)malloc(sizeof(struct node));

            if (frntNode == NULL)
            {
                cout << "Memory cannot be allocated";
                break;
            }
            else
            {
                cout << "Enter the data for node " << i << ": ";
                cin >> num;
                frntNode->num = num;
                frntNode->nextptr = NULL;
                tmp->nextptr = frntNode;
                tmp = tmp->nextptr;
            }
        }
    }
}

void display() // Function to display the linked list
{
    struct node* tmp;
    if (stnode == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        tmp = stnode;
        cout << "Linked List: ";
        while (tmp != NULL)
        {
            cout << tmp->num << " \t ";
            tmp = tmp->nextptr;
        }
    }
}

void printMiddle(struct node* stnode) // Function to print the middle node of the list
{
    struct node* single_ptr = stnode;
    struct node* twice_ptr = stnode;

    if (stnode != NULL)
    {
        while (twice_ptr != NULL && twice_ptr->nextptr != NULL)
        {
            twice_ptr = twice_ptr->nextptr->nextptr; // Moving with twice speed.
            single_ptr = single_ptr->nextptr;
        }
        cout << "The middle element is " << single_ptr->num << endl;
    }
}