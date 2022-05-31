#ifndef _SORT_H
#define _SORT_H
#include <stdlib.h>

void swap(int * a, int * b);
void merge(int array[], int left, int mid, int right);
void mergesort(int array[], int left, int right);
int partition(int array[], int left, int right);
int quicksort(int array[], int left, int right);
#endif