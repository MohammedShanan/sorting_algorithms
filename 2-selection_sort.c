#include "sort.h"
/**
 * selection_sort - sorts all selecty like
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
size_t i, j, smallest_idx;
int tmp, smallest;
if (array == NULL || size < 2)
{
return;
}
for (i = 0; i < size; i++)
{
smallest = array[i];
for (j = i; j < size; j++)
{
if (array[j] < smallest)
{
smallest = array[j];
smallest_idx = j;
}
}
if (smallest != array[i])
{
tmp = array[i];
array[i] = smallest;
array[smallest_idx] = tmp;
print_array(array, size);
}
}
}
