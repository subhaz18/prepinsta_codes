#include<iostream>
using namespace std;

struct node
{
  int num;
  node *nextptr;
} *stnode;			//node constructed

void make (int n);
int checkPalindrome (struct node **left, struct node *right);
int check (struct node *stnode);
void display ();


int main ()
{
  int n, num;

  cout << "Enter the number of nodes: ";
  cin >> n;
  make (n);
  cout << "\nLinked list data: \n";
  display ();
  if (check (stnode))
    cout << "\nLinked list is Palindrome";
  else
    cout << "\nLinked list is not Palindrome";

  return 0;
}

void make (int n)			//function to create linked list.
{
  struct node *frntNode, *tmp;
  int num, i;

  stnode = (struct node *) malloc (sizeof (struct node));
  if (stnode == NULL)
    {
      cout << "Memory can not be allocated";
    }
  else
    {

      cout << "Enter the data for node 1: ";
      cin >> num;
      stnode->num = num;
      stnode->nextptr = NULL;	//Links the address field to NULL
      tmp = stnode;

      for (i = 2; i <= n; i++)
	{
	  frntNode = (struct node *) malloc (sizeof (struct node));


	  if (frntNode == NULL)	//memory cannot be allotted if frntnode is NULL
	    {
	      cout << "Memory can not be allocated";
	      break;
	    }
	  else
	    {
	      cout << "Enter the data for node " << i << ": ";	// Entering data in nodes.
	      cin >> num;
	      frntNode->num = num;
	      frntNode->nextptr = NULL;
	      tmp->nextptr = frntNode;
	      tmp = tmp->nextptr;
	    }
	}
    }
}

void display ()			//function to diplay linked list
{
  struct node *tmp;
  if (stnode == NULL)
    {
      cout << "List is empty";
    }
  else
    {
      tmp = stnode;
      cout << "Linked List\t";
      while (tmp != NULL)
	{
	  cout << tmp->num << "\t";
	  tmp = tmp->nextptr;
	}
    }
}

int checkPalindrome (struct node **left, struct node *right)	// Function to check if linked list is palindrome or not
{
  if (right == NULL)
    return 1;

  int res = checkPalindrome (left, right->nextptr)
    && ((*left)->num == right->num);
  (*left) = (*left)->nextptr;

  return res;
}


int check (struct node *stnode)	// Function to check if linked list is palindrome or not recursively
{
  return checkPalindrome (&stnode, stnode);
}