/*
 *	Jonathan Ting
 *	Professor Emrich
 *	COSC 302
 *	Due 6 February 2019
 *	Project 2
 *	Overview: Sorts input either by string or numerically using either
 *  stl::sort, qsort, custom merge sort, or custom quick sort.
 */

// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <vector>


//Precondition: l.head is not NULL,
// compare_func is either node_number_compare or node_string compare.
//Postcondition: Sorts the list passed by reference using stl::sort
// either by string or numerically.
void stl_sort(List &l, bool (*compare_func)(const Node *, const Node *))
{
    //Stores the list nodes in a vector.
    std::vector<Node *> nodes;

    for(Node *curr = l.head; curr != NULL; curr = curr->next)
    {
        nodes.push_back(curr);
    }

    //Sorts the nodes using std::sort either by the node's string member or number member.
    std::sort(nodes.begin(), nodes.end(), compare_func);

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

