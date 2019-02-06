/*
 *	Jonathan Ting
 *	Professor Emrich
 *	COSC 302
 *	Due 6 February 2019
 *	Project 2
 *	Overview: Sorts input either by string or numerically using either
 *  stl::sort, qsort, custom merge sort, or custom quick sort.
 */

// main.cpp

#include "volsort.h"

#include <iostream>
#include <strings.h>
#include <unistd.h>
#include <cstdlib>

#define  MODE_STL       0
#define  MODE_QSORT     1
#define  MODE_MERGE     2
#define  MODE_QUICK     3
#define  MODE_OBLIVIOUS 4

// Utility functions -----------------------------------------------------------

//Precondition: Valid status.
//Postcondition: Displays usage text if
// invalid command line arguments were given.
void usage(int status)
{
    std::cout << "usage: volsort" << std::endl
              << "    -m MODE   Sorting mode (oblivious, stl, qsort, merge, quick)" << std::endl
              << "    -n        Perform numerical ordering"              << std::endl;
    
    exit(status);
}

//Precondition: Valid and correct number of command line arguments.
//Postcondition: Selects the relevant sort (or lack of)
// and whether sorted by string or numerically.
void parse_command_line_options(int argc, char *argv[], int &mode, bool &numeric)
{
    int c;

    while ((c = getopt(argc, argv, "hm:n")) != -1)
    {
        switch (c)
        {
            case 'm':
                if (strcasecmp(optarg, "stl") == 0)
                    mode = MODE_STL;
                else if (strcasecmp(optarg, "qsort") == 0)
                    mode = MODE_QSORT;
                else if (strcasecmp(optarg, "merge") == 0)
                    mode = MODE_MERGE;
                else if (strcasecmp(optarg, "quick") == 0)
                    mode = MODE_QUICK;
		        else if (strcasecmp(optarg, "oblivious") == 0)
		            mode = MODE_OBLIVIOUS;
                else
                    usage(1);
                break;

            case 'n':
                numeric = true;
                break;

            case 'h':
                usage(0);
                break;

            default:
                usage(1);
                break;
        }
    }
}

// Main execution --------------------------------------------------------------

int main(int argc, char *argv[])
{
    int mode = MODE_STL;
    bool numeric = false;

    List data;
    std::string line;

    bool (*compare_func)(const Node *, const Node *) = NULL;
    int (*cmp_func)(const void *, const void *) = NULL;
    
    //Parses command line arguments and selects sort mode.
    parse_command_line_options(argc, argv, mode, numeric);

    //Reads in data from input file and pushes into list.
    while (std::getline(std::cin, line)) {
        data.push_front(line);
    }

    //Selects whether sorting by string or numerically.
    if(numeric)
    {
        compare_func = node_number_compare;
        cmp_func = cmp_number;
    }
    else
    {
        compare_func = node_string_compare;
        cmp_func = cmp_string;
    }

    //Selects the sorting mode, either stl, qsort, merge, or quick.
    switch (mode) {
        case MODE_STL:
            stl_sort(data, compare_func);
            break;

        case MODE_QSORT:
            qsort_sort(data, cmp_func);
            break;

        case MODE_MERGE:
            merge_sort(data, compare_func);
            break;

        case MODE_QUICK:
            quick_sort(data, compare_func);
            break;
    }

    //Outputs the sorted (or nonsorted) list.
    for (Node * curr = data.head; curr != NULL; curr = curr->next)
    {
        if(numeric)
            std::cout << curr->number << std::endl;
        else
            std::cout << curr->string << std::endl;
    }

    //Ends program.
    return 0;
}
