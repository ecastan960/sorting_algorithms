#include "sort.h"
/**
 * bubble_sort - Doubly linked list node
 *
 * @array: Integer stored in the node
 * @size: Pointer to the previous element of the list
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, last, j;
	int temp = 0;

	if (array == NULL || size == 0)
		return;

	for (last = size - 1; last > 0; last--)
	{
		for (i = 0, j = 1; j <= last; i++, j++)
		{
			if (array[j] < array[i])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
}
