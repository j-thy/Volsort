/*
 *	Jonathan Ting
 *	Professor Emrich
 *	COSC 302
 *	Due 6 February 2019
 *	Project 2
 *	Overview: Sorts input either by string or numerically using either
 *  stl::sort, qsort, custom merge sort, or custom quick sort.
 */

// volsort.h

#ifndef VOLSORT_H
#define VOLSORT_H

#include <string>


struct Node
{
    std::string string;
    int number;
    Node *next;
};

struct List
{
    Node *head;
    size_t size;

    List();         //Defined in list.cpp.
    ~List();        //Defined in list.cpp.

    void push_front(const std::string &s);      //Defined in list.cpp.
};

// Functions -------------------------------------------------------------------

bool node_number_compare(const Node *a, const Node *b);     //Defined in list.cpp - used by quick, merge and stl.
bool node_string_compare(const Node *a, const Node *b);     //Defined in list.cpp - used by quick, merge and stl.
int cmp_number(const void *a, const void *b);               //Defined in list.cpp - used by qsort.
int cmp_string(const void *a, const void *b);               //Defined in list.cpp - used by qsort.


void dump_node(Node *n);        //Defined in list.cpp - to make it easier for TAs to grade.

void stl_sort(List &l, bool (*compare_func)(const Node *, const Node *));       //Defined in stl.cpp - sort using std::sort.
void qsort_sort(List &l, int (*cmp_func)(const void *, const void *));          //Defined in qsort.cpp - sort using qsort from cstdlib.
void merge_sort(List &l, bool (*compare_func)(const Node *, const Node *));     //Defined in merge.cpp - sort using my merge sort implementation.
void quick_sort(List &l, bool (*compare_func)(const Node *, const Node *));     //Defined in quick.cpp - sort using my quick sort implementation.

#endif