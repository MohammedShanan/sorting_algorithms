#include "sort.h"
/**
 * partition - partitions the array
 * @a: array to take in
 * @low: start of array;
 * @high: end of array
 * @size: full size of array
 * Return: position of pivot
 */
int partition(int a[], int low, int high, size_t size)
{
int pivot = a[high], tmp;
int i = low;
int j = high;
while (1)
{
while (a[i] < pivot)
{
i++;
}

while (a[j] > pivot)
{
j--;
}

if (i >= j)
{
return (i);
}

tmp = a[j];
a[j] = a[i];
a[i] = tmp;
print_array(a, size);
j--, i++;
}
}
/**
 * quicksort - quick sorts with recursion
 * @a: array to sort through
 * @lo: start of array or subarray
 * @hi: end of array or subarray
 * @size: size of full array
 */
void quicksort(int *a, int lo, int hi, size_t size)
{

int pivot;
if (lo >= hi)
{
return;
}
pivot = partition(a, lo, hi, size);

quicksort(a, lo, pivot - 1, size);

quicksort(a, pivot, hi, size);
}
/**
 * quick_sort_hoare - quick sorts with recursion
 * @array: array to sort through
 * @size: size of full array
 */
void quick_sort_hoare(int *array, size_t size)
{
quicksort(array, 0, size - 1, size);
}
