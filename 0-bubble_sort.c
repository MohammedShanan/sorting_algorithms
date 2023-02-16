#include "sort.h"
/**
 * bubble_sort - sorts bubbly
 * @array: array to sort
 * @size: size
 *
 */
void bubble_sort(int *array, size_t size)
{
size_t i;
int swap = 0, tmp;
if (array == NULL || size < 2)
{
return;
}
while (1)
{
swap = 0;
for (i = 0; i < size - 1; i++)
{
if (array[i] > array[i + 1])
{
tmp = array[i];
array[i] = array[i + 1];
array[i + 1] = tmp;
print_array(array, size);
swap = 1;
}
}
if (swap == 0)
{
return;
}
}
}
