#include "sort.h"

void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int array[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int * temp = (int*) malloc(sizeof(int) * (right - left + 1));
    while(i <= mid && j <= right) {
        if(array[i] < array[j]) {
            temp[k] = array[i++];
        } else {
            temp[k] = array[j++];
        }
        k++;
    }

    while(i <= mid) {
        temp[k] = array[i++];
        k++;
    }

    while(j <= right) {
        temp[k] = array[j++];
        k++;
    }

    for(k = left; k <= right; k++) {
        array[k] = temp[k - left];
    }
    free(temp);
}

void mergesort(int array[], int left, int right) {
    if(left < right) {
        int mid = (right + left) / 2;
        mergesort(array, left, mid);
        mergesort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int partition(int array[], int left, int right) {
    int j = left;
    for(int i = left; i < right; i++) {
        if(array[i] < array[right]) {
            swap(&array[i], &array[j]);
            j++;
        }
    }
    swap(&array[j], &array[right]);
    return j;
}

int quicksort(int array[], int left, int right) {
    if(left < right) {
        int pivot = partition(array, left, right);
        quicksort(array, left, pivot - 1);
        quicksort(array, pivot + 1, right);
    }   
}