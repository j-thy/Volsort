# cs302-project2
Volsort

Jonathan Ting
Professor Emrich
COSC 302
Due 6 February 2019
Project 2
Overview: Sorts input either by string or numerically using either stl::sort, qsort, custom merge sort, or custom quick sort.

Github: https://github.com/jonting/Volsort

1. Range of integers is 0 to (number of integers * 2)
| Numerical  | Mode    | Size       | Elapsed Time (ms)  | 
|------------|---------|------------|--------------------| 
| No         | STL     | 10         | 2                  | 
| No         | STL     | 100        | 2                  | 
| No         | STL     | 1000       | 4                  | 
| No         | STL     | 10000      | 28                 | 
| No         | STL     | 100000     | 385                | 
| No         | STL     | 1000000    | 8940               | 
| No         | STL     | 10000000   | 93207              | 
| Yes        | STL     | 10         | 2                  | 
| Yes        | STL     | 100        | 2                  | 
| Yes        | STL     | 1000       | 4                  | 
| Yes        | STL     | 10000      | 27                 | 
| Yes        | STL     | 100000     | 292                | 
| Yes        | STL     | 1000000    | 7376               | 
| Yes        | STL     | 10000000   | 84914              | 
| No         | QSORT   | 10         | 2                  | 
| No         | QSORT   | 100        | 2                  | 
| No         | QSORT   | 1000       | 4                  | 
| No         | QSORT   | 10000      | 27                 | 
| No         | QSORT   | 100000     | 288                | 
| No         | QSORT   | 1000000    | 6497               | 
| No         | QSORT   | 10000000   | 89242              | 
| Yes        | QSORT   | 10         | 2                  | 
| Yes        | QSORT   | 100        | 2                  | 
| Yes        | QSORT   | 1000       | 4                  | 
| Yes        | QSORT   | 10000      | 25                 | 
| Yes        | QSORT   | 100000     | 257                | 
| Yes        | QSORT   | 1000000    | 6285               | 
| Yes        | QSORT   | 10000000   | 73828              | 
| No         | MERGE   | 10         | 2                  | 
| No         | MERGE   | 100        | 2                  | 
| No         | MERGE   | 1000       | 4                  | 
| No         | MERGE   | 10000      | 26                 | 
| No         | MERGE   | 100000     | 280                | 
| No         | MERGE   | 1000000    | 6138               | 
| No         | MERGE   | 10000000   | 79639              | 
| Yes        | MERGE   | 10         | 2                  | 
| Yes        | MERGE   | 100        | 2                  | 
| Yes        | MERGE   | 1000       | 4                  | 
| Yes        | MERGE   | 10000      | 25                 | 
| Yes        | MERGE   | 100000     | 262                | 
| Yes        | MERGE   | 1000000    | 5044               | 
| Yes        | MERGE   | 10000000   | 76138              | 
| No         | QUICK   | 10         | 2                  | 
| No         | QUICK   | 100        | 2                  | 
| No         | QUICK   | 1000       | 4                  | 
| No         | QUICK   | 10000      | 28                 | 
| No         | QUICK   | 100000     | 320                | 
| No         | QUICK   | 1000000    | 6176               | 
| No         | QUICK   | 10000000   | 96193              | 
| Yes        | QUICK   | 10         | 2                  | 
| Yes        | QUICK   | 100        | 2                  | 
| Yes        | QUICK   | 1000       | 4                  | 
| Yes        | QUICK   | 10000      | 26                 |  
| Yes        | QUICK   | 100000     | 295                | 
| Yes        | QUICK   | 1000000    | 5760               | 
| Yes        | QUICK   | 10000000   | 90532              | 

2.
    a. Each sort is around the same for 10-10000 entries. For most cases past 10000 entries, quick sort is fastest with qsort as second fastest.
       Quicksort is closer to merge sort in the 1000000 entries range and stl is slowest in the 10000-1000000 entries range, however quicksort is also slowest in the 10000000 entries range.
       Merge sort is generally fastest due to the efficiency of the algorithm, along with qsort.
       Quicksort is fairly fast due to the algoritm but is slower in the very large entry amounts possibly due to my different implementation, where it may still rotate old pivots.
       STL sort is generally the slowest, probably because of more overhead as it needs to be applicable to more usages.
       Numerical sort is always faster than non-numerical sort.
    b. Actual performance is very reliant on the implementation and also the amount of entries. For example, quick sort is fast in the middle size entries but worst in the very large entries.
       The average case vs. worst case complexities actually reflect that reality in quicksort, where the very large entries is arguably a worst case complexity.
    c. Merge sort is the best. It has the fastest time in all the size categories. It appears to have no trade offs, but that might be due to an imperfect quicksort implementation.
       Normally, quick sort would be faster in the mid-range entries.

3. Since I was the only member of my team, I performed all the planning, coding, testing, and commenting.