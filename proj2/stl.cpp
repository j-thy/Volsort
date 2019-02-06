// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <iostream>
#include <vector>

void stl_sort(List &l, bool numeric)
{
    std::vector<Node *> nodes;
    for(Node *curr = l.head; curr != NULL; curr = curr->next)
    {
        nodes.push_back(curr);
    }

    switch(numeric)
    {
        case true:
            std::sort(nodes.begin(), nodes.end(), node_number_compare);
            break;
        case false:
            std::sort(nodes.begin(), nodes.end(), node_string_compare);
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

