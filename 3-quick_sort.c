#include "sort.h"
/**
 * partition - partitions the array
 * @array: array to take in
 * @start: start of array;
 * @end: end of array
 * @size: full size of array
 * Return: position of pivot
 */
size_t partition(int *array, int start, int end, size_t size)
{
    int pivot = array[end];
    int i = start, j, tmp;
    for (j = start; j < end; j++)
    {
        if (array[j] <= pivot)
        {
            if (i != j)
            {
                tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
                print_array(array, size);
            }
            i++;
        }
    }
    if (i != end)
    {
        tmp = array[i];
        array[i] = pivot;
        array[end] = tmp;
        print_array(array, size);
    }
    return (i);
}
/**
 * _quick_sort - quick sorts with recursion
 * @array: array to sort through
 * @size: size of full array
 * @start: start of array or subarray
 * @end: end of array or subarray
 */
void _quick_sort(int *array, size_t size, int start, int end)
{
    int pivot_idx;
    if (start < end)
    {
        pivot_idx = partition(array, start, end, size);
        _quick_sort(array, size, start, pivot_idx - 1);
        _quick_sort(array, size, pivot_idx + 1, end);
    }
}
/**
 * quick_sort - quick sorts an array
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
    {
        return;
    }
    _quick_sort(array, size, 0, size - 1);
}