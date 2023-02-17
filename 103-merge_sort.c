#include "sort.h"
/**
 * prints - prints left, right, and merged halves
 * @arr: original or tmp array
 * @msg: left, right, or merged half
 * @start: starting index
 * @end: ending index
 */
void prints(int *arr, char *msg, size_t start, size_t end)
{
size_t i;
printf("[%s]: ", msg);
for (i = start; i < end; i++)
{
if (i < end - 1)
{
printf("%d, ", arr[i]);
}
else
{
printf("%d\n", arr[i]);
}
}
}
/**
 * _merge_sort - recursively splits and merges halves
 * @array: original array
 * @sorted_arr: tmp array to hold sorted elements
 * @start: starting index
 * @end: ending index
 */
void _merge_sort(int *array, int *sorted_arr, size_t start, size_t end)
{
size_t mid, left_indx, right_indx, i;
mid = (start + end) / 2;
if (end - start <= 1)
{
return;
}

_merge_sort(array, sorted_arr, start, mid);
_merge_sort(array, sorted_arr, mid, end);
printf("Merging...\n");
left_indx = start;
right_indx = mid;
prints(array, "left", left_indx, mid);
prints(array, "right", mid, end);
for (i = start; i < end; i++)
{
if ((left_indx < mid) &&
(right_indx == end || array[left_indx] < array[right_indx]))
{
sorted_arr[i] = array[left_indx];
left_indx++;
}
else
{
sorted_arr[i] = array[right_indx];
right_indx++;
}
}
prints(sorted_arr, "Done", start, end);
for (i = start; i < end; i++)
{
array[i] = sorted_arr[i];
}
}
/**
 * merge_sort - sorts mergly
 * @array: array sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
int *sorted_arr;
if (array == NULL || size < 2)
{
return;
}
sorted_arr = malloc(sizeof(int) * size);
if (sorted_arr == NULL)
{
return;
}
_merge_sort(array, sorted_arr, 0, size);
free(sorted_arr);
}
