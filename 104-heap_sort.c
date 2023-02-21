#include "sort.h"
/**
 * swap - swap two nodes
 * @a: pointer to the first node
 * @b: pointer to the second node
 */
void swap(int *a, int *b)
{

int temp = *a;

*a = *b;

*b = temp;
}
/**
 * heapify - create max heap
 * @arr: array sort
 * @N: size of heap
 * @i: index of root node
 * @size: size of array
 */
void heapify(int *arr, int N, int i, size_t size)
{

int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < N && arr[left] > arr[largest])

largest = left;
if (right < N && arr[right] > arr[largest])

largest = right;
if (largest != i)
{

swap(&arr[i], &arr[largest]);
print_array(arr, size);
heapify(arr, N, largest, size);
}
}
/**
 * heap_sort - heap sort algo
 * @array: array sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
int i;
if (array == NULL || size < 2)
{
return;
}
for (i = size / 2 - 1; i >= 0; i--)
heapify(array, size, i, size);
for (i = size - 1; i >= 0; i--)
{
if (i != 0)
{
swap(&array[0], &array[i]);
print_array(array, size);
}
heapify(array, i, 0, size);
}
}
