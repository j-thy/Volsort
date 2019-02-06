/*
 *	Jonathan Ting
 *	Professor Emrich
 *	COSC 302
 *	Due 6 February 2019
 *	Project 2
 *	Overview: Sorts input either by string or numerically using either
 *  stl::sort, qsort, custom merge sort, or custom quick sort.
 */

// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <vector>


//Precondition: l.head is not NULL, cmp_func is either
// cmp_number or cmp_string.
//Postcondition: Sorts the list passed by reference using qsort
// either by string or numerically.
void qsort_sort(List &l, int (*cmp_func)(const void *, const void *))
{
    //Stores the list nodes in a vector.
    std::vector<Node *> nodes;

    for(Node *curr = l.head; curr != NULL; curr = curr->next)
    {
        nodes.push_back(curr);
    }

    //Sorts the nodes using qsort either by the node's string member or number member.
    qsort(&nodes[0], nodes.size(), sizeof(Node *), cmp_func);

    //Sets the new head node of the sorted list.
    l.head = nodes[0];

    //Re-links all the nodes in the vector in sorted order.
    for(unsigned int i = 0; i < nodes.size(); i++)
    {
        if(i != nodes.size() - 1)
            nodes[i]->next = nodes[i + 1];
        else
            nodes[i]->next = NULL;
    }
}

