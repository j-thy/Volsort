#include "volsort.h"


List::List()
{
    head = NULL;
    size = 0;
}

List::~List()
{
    Node *next;
    for(Node *curr = head; curr != NULL; curr = next)
    {
        next = curr->next;
        delete curr;
    }
}

void List::push_front(const std::string &s)
{
    //Creates a new node storing the string.
    Node *newnode;
    newnode = new Node;
    newnode->string = s;

	try
    {
        newnode->number = std::stoi(s);
    }
    catch(...)
    {
        newnode->number = 0;
    }
    
    //Links the new node to the sentinel node and the previous first node.
    newnode->next = head;

    //Links the forward pointer of the sentinel node to the new node.
    head = newnode;

    //Increments the list size.
    size++;
}

bool node_number_compare(const Node *a, const Node *b)
{
    if(a->number <= b->number)
        return true;
    else
        return false;
}

bool node_string_compare(const Node *a, const Node *b)		//implement in this file (volsort.h), used by quick, merge and stl
{
    if(a->string <= b->string)
        return true;
    else
        return false;
}

int cmp_number(const void *a, const void *b)
{
    Node *node_a = *(Node **)a;
    Node *node_b = *(Node **)b;

    if (node_a->number > node_b->number)
        return 1;
    else if (node_a->number < node_b->number)
        return -1;
    return 0;
}

int cmp_string(const void *a, const void *b)
{
    Node *node_a = *(Node **)a;
    Node *node_b = *(Node **)b;
    
    if (node_a->string > node_b->string)
        return 1;
    else if (node_a->string < node_b->string)
        return -1;
    return 0;
}

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