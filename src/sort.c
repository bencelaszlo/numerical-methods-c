#include "vec.h"

#define SWAP(T, a, b) do { T tmp = a; a = b; b = tmp; } while (0)

void shell_sort(int n, Vec *a) {
    int gap = (n / 2);
    float temp;
    int j;

    while (gap > 0) {
        for (int i = gap; i < n; i++) {
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