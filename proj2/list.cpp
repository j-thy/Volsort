/*
 *	Jonathan Ting
 *	Professor Emrich
 *	COSC 302
 *	Due 6 February 2019
 *	Project 2
 *	Overview: Sorts input either by string or numerically using either
 *  stl::sort, qsort, custom merge sort, or custom quick sort.
 */

// list.cpp

#include "volsort.h"


//List constructor.
List::List()
{
    head = NULL;
    size = 0;
}

//List deconstructor.
List::~List()
{
    Node *next;

    for(Node *curr = head; curr != NULL; curr = next)
    {
        next = curr->next;
        delete curr;
    }
}

//Precondition: s is a valid string or a number.
//Postcondition: Adds a new node containing the string
// and the value as an int to the list.
void List::push_front(const std::string &s)
{
    //Creates a new node storing the string.
    Node *newnode;
    newnode = new Node;
    newnode->string = s;

    //Stores the string as a number.
	try
    {
        newnode->number = std::stoi(s);
    }
    //If not a valid number, stores string as 0.
    catch(...)
    {
        newnode->number = 0;
    }
    
    //Links the new node to the original head node of the list.
    newnode->next = head;

    //Sets the new node as the head node.
    head = newnode;

    //Increments the list size.
    size++;
}

//Precondition: a and b are not NULL.
//Postcondition: The return value is true if
// (comparing number) a <= b or false if a > b.
bool node_number_compare(const Node *a, const Node *b)
{
    //Compares the number member of 2 nodes.
    if(a->number <= b->number)
        return true;

    return false;
}

//Precondition: a and b are not NULL.
//Postcondition: The return value is true if
// (comparing string) a <= b or false if a > b.
bool node_string_compare(const Node *a, const Node *b)
{
    //Compares the string member of 2 nodes.
    if(a->string <= b->string)
        return true;

    return false;
}

//Precondition: a and b are not NULL.
//Postcondition: The return value is 1 if
// (comparing number) a > b, -1 if a < b, 0 if a = b.
int cmp_number(const void *a, const void *b)
{
    //Typecasts parameters to nodes.
    Node *node_a = *(Node **)a;
    Node *node_b = *(Node **)b;

    //Compares the number member of 2 nodes.
    if (node_a->number > node_b->number)
        return 1;
    else if (node_a->number < node_b->number)
        return -1;

    return 0;
}

//Precondition: a and b are not NULL.
//Postcondition: The return value is 1 if
// (comparing string) a > b, -1 if a < b, 0 if a = b.
int cmp_string(const void *a, const void *b)
{
    //Typecasts parameters to nodes.
    Node *node_a = *(Node **)a;
    Node *node_b = *(Node **)b;
    
    //Compares the string member of 2 nodes. 
    if (node_a->string > node_b->string)
        return 1;
    else if (node_a->string < node_b->string)
        return -1;

    return 0;
}

//Precondition: n is not NULL.
//Postcondition: Prints out node contents of given node
// and every linked node in order until reaching NULL pointer.
void dump_node(Node *n)
{
    printf("!! DUMP START !!\n");

    for(Node *curr = n; curr != NULL; curr = curr->next)
    {
        printf("String: %s\nNum: %d\n", curr->string.c_str(), curr->number);

        if(curr->next != NULL)
            printf("Next: %s\n", curr->next->string.c_str());

        printf("\n");
    }

    printf("\n");
}