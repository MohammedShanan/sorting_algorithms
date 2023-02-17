#include "sort.h"
/**
 * counting_sort - counting sort algo
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
int *counts, *sorted_arr, indx, k = array[0];
size_t i = 0;
if (array == NULL || size < 2)
return;
for (i = 0; i < size; i++)
k = array[i] > k ? array[i] : k;
counts = malloc(sizeof(int) * (k + 1));
if (counts == NULL)
return;
sorted_arr = malloc(sizeof(int) * size);
if (sorted_arr == NULL)
{
free(counts);
return;
}
for (indx = 0; indx < k + 1; indx++)
counts[indx] = 0;
for (i = 0; i < size; i++)
{
counts[array[i]] += 1;
}
for (indx = 0; indx < k; indx++)
{
counts[indx + 1] += counts[indx];
}
print_array(counts, k + 1);
for (i = size; i > 0; i--)
{
indx = counts[array[i - 1]] - 1;
sorted_arr[indx] = array[i - 1];
counts[array[i - 1]] -= 1;
}
for (i = 0; i < size; i++)
array[i] = sorted_arr[i];
free(sorted_arr);
free(counts);
}
