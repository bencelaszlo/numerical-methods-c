#ifndef _SORT_H_
#define _SORT_H_

    void heapify(Vec *a, unsigned n, unsigned i);

    void heapsort(unsigned n, Vec *a);

    void shell_sort(int n, Vec *a);

    void quicksort(int low, int high, Vec *arr);

    int partition(int low, int high, Vec *arr);

#endif