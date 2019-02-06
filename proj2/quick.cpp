// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric)
{
    l.head = qsort(l.head, numeric);
}

Node *qsort(Node *head, bool numeric)
{
    if(head == NULL)
    {
        return head;
    }
    Node *left = head;
    Node *right = NULL;

    Node *pivot = head;
    Node *fast = head;
 
    while(pivot != NULL && fast != NULL && fast->next != NULL)
    {
        pivot = pivot->next;
        fast = fast->next->next;
    }
    
    if(pivot->next == NULL)
    {
        right = pivot;
    }
    else
    {
        right = pivot->next;
    }

    switch(numeric)
    {
        case true:
            if(left->next != NULL && (left->next->next != NULL || !node_number_compare(left, right)))
            {
                partition(head, pivot, left, right, numeric);
                left = qsort(left, numeric);
                right = qsort(right, numeric);
                return concatenate(left, right);
            }
            break;
        case false:
            if(left->next != NULL && (left->next->next != NULL || !node_string_compare(left, right)))
            {
                partition(head, pivot, left, right, numeric);
                left = qsort(left, numeric);
                right = qsort(right, numeric);
                return concatenate(left, right);
            }
    }


    return head;
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric)
{
    Node *curr_less = NULL;
    Node *curr_greater = NULL;
    head = NULL;

    while(left != pivot)
    {
        switch(numeric)
        {
            case true:
                if(node_number_compare(left, pivot))
                {
                    if(curr_less == NULL)
                        head = left;
                    else
                        curr_less->next = left;
                    curr_less = left;
                    left = left->next;
                }
                else
                {
                    if(curr_greater == NULL)
                        pivot->next = left; 
                    else
                        curr_greater->next = left;
                    curr_greater = left;
                    left = left->next;
                }
                break;
            case false:
                if(node_string_compare(left, pivot))
                {
                    if(curr_less == NULL)
                        head = left;
                    else
                        curr_less->next = left;
                    curr_less = left;
                    left = left->next;
                }
                else
                {
                    if(curr_greater == NULL)
                        pivot->next = left; 
                    else
                        curr_greater->next = left;
                    curr_greater = left;
                    left = left->next;
                }
                break;
        }
    }
    while(right != NULL && right != pivot)
    {
        switch(numeric)
        {
            case true:
                if(node_number_compare(right, pivot))
                {
                    if(curr_less == NULL)
                        head = right;
                    else
                        curr_less->next = right;
                    curr_less = right;
                    right = right->next;
                }
                else
                {
                    if(curr_greater == NULL)
                        pivot->next = right;
                    else
                        curr_greater->next = right;
                    curr_greater = right;
                    right = right->next;
                }
                break;
            case false:
                if(node_string_compare(right, pivot))
                {
                    if(curr_less == NULL)
                        head = right;
                    else
                        curr_less->next = right;
                    curr_less = right;
                    right = right->next;
                }
                else
                {
                    if(curr_greater == NULL)
                        pivot->next = right;
                    else
                        curr_greater->next = right;
                    curr_greater = right;
                    right = right->next;
                }
                break;
        }
    }
    if(curr_less != NULL)
        curr_less->next = NULL;
    if(curr_greater != NULL)
        curr_greater->next = NULL;
    else
        pivot->next = NULL;
    left = head;
    right = pivot;
}

Node *concatenate(Node *left, Node *right)
{
    if(left == NULL)
    {
        return right;
    }
    if(right == NULL)
    {
        return left;
    }
        Node *curr = left;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = right;
        return left;
}

