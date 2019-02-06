/*
 *	Jonathan Ting
 *	Professor Emrich
 *	COSC 302
 *	Due 6 February 2019
 *	Project 2
 *	Overview: Sorts input either by string or numerically using either
 *  stl::sort, qsort, custom merge sort, or custom quick sort.
 */

// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool (*compare_func)(const Node *, const Node *));
void partition(Node *pivot, Node *&left, Node *&right, bool (*compare_func)(const Node *, const Node *));
Node *concatenate(Node *left, Node *right);

// Implementations

//Precondition: l.head is not NULL, compare_func is either
// node_number_compare or node_string_compare.
//Postcondition: Sets the head of the list to the beginning node of
// the new sorted list.
void quick_sort(List &l, bool (*compare_func)(const Node *, const Node *))
{
    l.head = qsort(l.head, compare_func);
}

//Precondition: Head is either list head or starting node of sublist,
// compare_func is either node_number_compare or node_string compare.
//Postcondition: Returns node at starting node of a list after creating sublists recursively by
// pivoting nodes around a pivot by value and then concatenating sorted sublists (recursive).
Node *qsort(Node *head, bool (*compare_func)(const Node *, const Node *))
{
    //Returns to parent if a NULL branch is created.
    if(head == NULL)
        return head;

    //Sets the start of the nodes to the left of the pivot at the head of the list.
    Node *left = head;
    Node *right = NULL;
    Node *pivot = head;
    Node *fast = head;
 
    //Uses slow and fast pointer trick to find the middle node of the list,
    // which is used as the pivot.
    while(pivot != NULL && fast != NULL && fast->next != NULL)
    {
        pivot = pivot->next;
        fast = fast->next->next;
    }
    
    //In a 2-node list, the start of the nodes to the right of the pivot pointer
    // is the same as the pivot.
    if(pivot->next == NULL)
        right = pivot;
    else
        right = pivot->next;

    //Partitions the list into a sublist with values less than pivot and
    // a sublist with values greater than pivot and recursively partitions those lists.
    // Only partitions if not a 2-node sorted list or 1-node list.
    // Concatenates after no more partitions can be done.
    if(left->next != NULL && (left->next->next != NULL || !(*compare_func)(left, right)))
    {
        partition(pivot, left, right, compare_func);

        left = qsort(left, compare_func);
        right = qsort(right, compare_func);

        return concatenate(left, right);
    }

    return head;
}

//Precondition: left is the head node and right is the node after pivot (or pivot if a 2-node list),
// pivot is the middle node (or node to the right of middle if size of list is even),
// compare_func is either node_number_compare or node_string compare.
//Postcondition: Stores list of nodes smaller than pivot in the left sublist
// and the pivot and nodes greater than pivot in the right sublist.
void partition(Node *pivot, Node *&left, Node *&right, bool (*compare_func)(const Node *, const Node *))
{
    Node *curr_less = NULL;
    Node *curr_greater = NULL;
    Node *head = NULL;

    //Compares all the nodes to the left of the pivot with the pivot and stores them
    // in the left sublist if less or in the right sublist after the pivot if greater.
    while(left != pivot)
    {
        //Stores node in the left sublist if less than the pivot. 
        if((*compare_func)(left, pivot))
        {
            if(curr_less == NULL)
                head = left;
            else
                curr_less->next = left;

            curr_less = left;
            left = left->next;
        }
        //Stores node in the right sublist after the pivot if greater than the pivot. 
        else
        {
            if(curr_greater == NULL)
                pivot->next = left; 
            else
                curr_greater->next = left;

            curr_greater = left;
            left = left->next;
        }
    }

    //Compares all the nodes to the right of the pivot with the pivot and stores them
    // in the left sublist if less or in the right sublist after the pivot if greater.
    while(right != NULL && right != pivot)
    {
        //Stores node in the left sublist if less than the pivot.
        if((*compare_func)(right, pivot))
        {
            if(curr_less == NULL)
                head = right;
            else
                curr_less->next = right;

            curr_less = right;
            right = right->next;
        }
        //Stores node in the right sublist after the pivot if greater than the pivot.
        else
        {
            if(curr_greater == NULL)
                pivot->next = right;
            else
                curr_greater->next = right;

            curr_greater = right;
            right = right->next;
        }
    }

    //Ensures the sublists are NULL terminated.
    if(curr_less != NULL)
        curr_less->next = NULL;
    if(curr_greater != NULL)
        curr_greater->next = NULL;
    else
        pivot->next = NULL;

    //Sets the left and the right pointers to the start of their respective sublists.
    left = head;
    right = pivot;
}

//Precondition: left and right are either valid nodes or NULL.
//Postcondition: Returns a merged list, or original list if one list is NULL.
Node *concatenate(Node *left, Node *right)
{
    //Returns original list if one list is NULL.
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;

    //Locates the end of the left sublist.
    Node *curr = left;

    while(curr->next != NULL)
        curr = curr->next;

    //Connects the end of the left sublist with the start of the right sublist.
    curr->next = right;

    //Return the concatenated list.
    return left;
}