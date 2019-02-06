// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <array>
#include <iostream>
#include <vector>

void qsort_sort(List &l, bool numeric)
{
    std::vector<Node *> nodes;
    for(Node *curr = l.head; curr != NULL; curr = curr->next)
    {
        nodes.push_back(curr);
    }
    switch(numeric)
    {
        case true:
            qsort(&nodes[0], nodes.size(), sizeof(Node *), cmp_number);
            break;
        case false:
            qsort(&nodes[0], nodes.size(), sizeof(Node *), cmp_string);
            break;
    }
    l.head = nodes[0];
    for(unsigned int i = 0; i < nodes.size(); i++)
    {
        if(i != nodes.size()-1)
            nodes[i]->next = nodes[i+1];
        else
            nodes[i]->next = NULL;
    }
}

