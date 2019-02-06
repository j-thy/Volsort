/*
 *	Jonathan Ting
 *	Professor Emrich
 *	COSC 302
 *	Due 6 February 2019
 *	Project 2
 *	Overview: Sorts input either by string or numerically using either
 *  stl::sort, qsort, custom merge sort, or custom quick sort.
 */

// merge.cpp

#include "volsort.h"

// Prototypes

Node *msort(Node *head, bool (*compare_func)(const Node *, const Node *));
void split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool (*compare_func)(const Node *, const Node *));

// Implementations

//Precondition: l.head is not NULL, compare_func is either
// node_number_compare or node_string_compare.
//Postcondition: Sets the head of the list to the beginning node of
// the new sorted list.
void merge_sort(List &l, bool (*compare_func)(const Node *, const Node *))
{
    l.head = msort(l.head, compare_func);
}

//Precondition: Head is either list head or starting node of sublist,
// compare_func is either node_number_compare or node_string compare.
//Postcondition: Returns node at starting node of a list after splitting sublists recursively
// and then merging split sublists in sorted order (recursive).
Node *msort(Node *head, bool (*compare_func)(const Node *, const Node *))
{
    Node *left = NULL;
    Node *right = NULL;

    //Divides into left and right sublists and recursively divides those lists
    // if list size is greater than 1 node.
    if(head->next != NULL)
    {
        split(head, left, right);
        right = msort(right, compare_func);
        left = msort(left, compare_func);
    }

    //Sorts and combines left and right sublists (base case).
    if(left != NULL && right != NULL)
        return merge(left, right, compare_func);

    //Returns unmodified list if it neither split nor merged.
    return head;
}

//Precondition: head and head->next are not NULL,
// left and right are NULL.
//Postcondition: Stores list of nodes split down the middle
// in the left and right nodes passed by reference.
void split(Node *head, Node *&left, Node *&right)
{
    Node *slow = head;
    Node *fast = head;
    Node *split = head;
 
    //Uses slow and fast pointer trick to find the middle of the list.
    while(slow != NULL && fast != NULL && fast->next != NULL)
    {
        split = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    //Splits the list down the middle.
    split->next = NULL;

    //Stores the left and right lists in nodes passed by reference.
    left = head;
    right = slow;
}

//Precondition: left and right are either valid nodes or NULL,
// compare_func is either node_number_compare or node_string compare.
//Postcondition: Returns a merged, sorted list, or original list if one list is NULL.
Node *merge(Node *left, Node *right, bool (*compare_func)(const Node *, const Node *))
{
    //Returns the other list if one list is empty.
    if(left == NULL)
        return right;
    else if(right == NULL)
        return left;

    Node *head = NULL;

    //Compares the starting node of the two lists and sets
    // the smaller of the two as the head of the new list.
    if((*compare_func)(left, right))
    {
        head = left;
        left = left->next;
    }
    else
    {
        head = right;
        right = right->next;
    }

    //Sets the current position of the back of the new list.
    Node *curr = head;

    //Merges the two lists into one sorted list.
    while(left != NULL || right != NULL)
    {
        //Places right node in back of the new list if left list is out of nodes to sort.
        if(left == NULL)
        {
            curr->next = right;
            curr = right;
            right = right->next;
        }
        //Places left node in back of the new list if right list is out of nodes to sort.
        else if(right == NULL)
        {
            curr->next = left;
            curr = left;
            left = left->next;
        }
        //Places left node in back of the new list if left node is less than right node.
        else if((*compare_func)(left, right))
        {
            curr->next = left;
            curr = left;
            left = left->next;
        }
        //Places right node in back of the new list if right node is less than left node.
        else
        {
            curr->next = right;
            curr = right;
            right = right->next;
        }
    }

    //Returns the sorted list.
    return head;
}

