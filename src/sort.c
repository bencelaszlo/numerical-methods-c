#include "vec.h"

#define SWAP(T, a, b) do { T tmp = a; a = b; b = tmp; } while (0)

void heapify(Vec *a, unsigned n, unsigned i) {
    unsigned largest = i;
    unsigned l = 2 * i + 1;
    unsigned r = 2 * i + 2;

    if ( (r < n) && (a->elements[i] < a->elements[l]) ) {
        largest = l;
    }

    if ( (r < n) && (a->elements[largest] < a->elements[r]) ) {
        largest = r;
    }

    if (largest != i) {
        SWAP(float, a->elements[largest], a->elements[i]);

        heapify(a, n, largest);
    }
}

void heapsort(unsigned n, Vec *a) {
    // Build a maxheap
    unsigned i = n;
    while (i > 0) {
        heapify(a, n, i);
        i -= 1;
    }

    // One by one extract elements
    i = n - 1;
    while (i > 0) {
        SWAP(float, a->elements[0], a->elements[i]);
        heapify(a, i ,0);
        i -= 1;
    }
}

void shell_sort(unsigned n, Vec *a) {
    int gap = (n / 2);
    float temp;
    int j;

    while (gap > 0) {
        for (unsigned i = gap; i < n; i++) {
            temp = a->elements[i];
            
            j = i;
            while ( (j >= gap) && (a->elements[(j-gap)] > temp) ) {
                a->elements[j] = a->elements[(j-gap)];
                j -= gap;
            }
            a->elements[j] = temp;
        }
        gap /= 2;
    }
}

int partition(int low, int high, Vec *arr) {
    float pivot;

    // Choose pivot element with the "median-of-three" rule
    int mid = (low + high) / 2;
    if (arr->elements[mid] < arr->elements[low]) {
        SWAP(float, arr->elements[low], arr->elements[high]);
    }

    if (arr->elements[high] < arr->elements[low]) {
        SWAP(float, arr->elements[low], arr->elements[high]);
    }

    if (arr->elements[mid] < arr->elements[high]) {
        SWAP(float, arr->elements[mid], arr->elements[high]);
    }

    pivot = arr->elements[high];

    int i;
    int j;

    i = low - 1;
	j = high + 1;

    while (1) {
        while (1) {
            i += 1;
            if (arr->elements[i] >= pivot) {
                break;
            }
        }

        while (1) {
            j -= 1;
            if (arr->elements[j] <= pivot) {
                break;
            }
        }

        if (i >= j) {
            return j;
        }

        SWAP(float, arr->elements[i], arr->elements[j]);
    }
}

void quicksort(int low, int high, Vec *arr) {
    if (low < high) {
        int p = partition(low, high, arr);
        quicksort(low, p, arr);
        quicksort(p+1, high, arr);
    } else {
        return;
    }
}
