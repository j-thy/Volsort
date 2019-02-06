// merge.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, bool numeric);
void split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric)
{
    l.head = msort(l.head, numeric);
}

Node *msort(Node *head, bool numeric)
{
    Node *left = NULL;
    Node *right = NULL;
    // Handle base case

    // Divide into left and right sublists
    if(head->next != NULL)
    {
        split(head, left, right);
        right = msort(right, numeric);
        left = msort(left, numeric);
    }

    // Conquer left and right sublists
    if(left != NULL && right != NULL)
    {
        return merge(left, right, numeric);
    }

    return head;
    // Combine left and right sublists
}

void split(Node *head, Node *&left, Node *&right)
{
    Node *slow = head;
    Node *fast = head;
    Node *split = head;
 
    while(slow != NULL && fast != NULL && fast->next != NULL)
    {
        split = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    split->next = NULL;

    left = head;
    right = slow;
}

Node *merge(Node *left, Node *right, bool numeric)
{
    if(left == NULL)
        return right;
    else if(right == NULL)
        return left;

    Node *head = NULL;

    switch(numeric)
    {
        case true:
            if(node_number_compare(left, right))
            {
                head = left;
                left = left->next;
            }
            else
            {
                head = right;
                right = right->next;
            }
            break;
        case false:
            if(node_string_compare(left, right))
            {
                head = left;
                left = left->next;
            }
            else
            {
                head = right;
                right = right->next;
            }
            break;
    }

    Node *curr = head;

    while(left != NULL || right != NULL)
    {
        switch(numeric)
        {
            case true:
                if(left == NULL)
                {
                    curr->next = right;
                    curr = right;
                    right = right->next;
                }
                else if(right == NULL)
                {
                    curr->next = left;
                    curr = left;
                    left = left->next;
                }
                else if(node_number_compare(left, right))
                {
                    curr->next = left;
                    curr = left;
                    left = left->next;
                }
                else
                {
                    curr->next = right;
                    curr = right;
                    right = right->next;
                }
                break;
            case false:
                if(left == NULL)
                {
                    curr->next = right;
                    curr = right;
                    right = right->next;
                }
                else if(right == NULL)
                {
                    curr->next = left;
                    curr = left;
                    left = left->next;
                }
                else if(node_string_compare(left, right))
                {
                    curr->next = left;
                    curr = left;
                    left = left->next;
                }
                else
                {
                    curr->next = right;
                    curr = right;
                    right = right->next;
                }
                break;
        }
    }
return head;
}

