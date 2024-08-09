#include<iostream>
using namespace std;
struct node
{
    int num;
    node *nextptr;
};node* stnode = nullptr; // Initialize stnode to nullptrvoid make(int n)
{
    node *frntNode, *tmp;
    int num, i;
    stnode = new node;
    if(stnode == nullptr)
    {
        cout<<"Memory can not be allocated";
        return;
    }
    else
    {
        cout<<"Enter the data for node 1: ";
        cin>>num;
        stnode->num = num;
        stnode->nextptr = nullptr; // Initialize next pointer to nullptr
        tmp = stnode;
        for(i=2; i<=n; i++)
        {
            frntNode = new node;
            if(frntNode == nullptr)
            {
                cout<<"Memory can not be allocated";
                break;
            }
            else
            {
                cout<<"Enter the data for node "<>num;
                frntNode->num = num;
                frntNode->nextptr = nullptr;
                tmp->nextptr = frntNode;
                tmp = tmp->nextptr;
            }
        }
    }
}node* getkthLastNode(node* stnode, int k, int n)
{
    node *front, *back;
    int i;
    front = back = stnode;
    if(k > n)
    {
        cout << "\nk is greater than the size of Linked List\n";
        return nullptr;
    }
    for(i = 0; i < k-1; i++)
    {
        front = front->nextptr;
    }
    while(front->nextptr != nullptr)
    {
        front = front->nextptr;
        back = back->nextptr;
    }
    return back;
}void print()
{
    node *tmp;
    if(stnode == nullptr)
    {
        cout<<"List is empty";
    }
    else
    {
        tmp = stnode;
        cout<<"Linked List\t";
        while(tmp != nullptr)
        {
            cout<num<<"\t";
            tmp = tmp->nextptr;
        }
    }
}int main()
{
    int n, k;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    make(n);
    cout<<"\nLinked list data: \n";
    print();
    cout<<"\nEnter the value of k:";
    cin>>k;
    cout<< endl;
    node* result = getkthLastNode(stnode, k, n);
    if(result != nullptr)
    {
        cout << "Kth node from the end: " << result->num << endl;
    }
    else
    {
        cout << "Invalid input for k." << endl;
    }    // Free the allocated memory
    node* current = stnode;
    while(current != nullptr)
    {
        node* next = current->nextptr;
        delete current;
        current = next;
    }
}