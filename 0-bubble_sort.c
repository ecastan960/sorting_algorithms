#include "sort.h"
/**
 * bubble_sort - Doubly linked list node
 *
 * @array: Integer stored in the node
 * @size: Pointer to the previous element of the list
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, last;
	int temp = 0;

	for (last = size - 1; last > 0; last--)
	{
		for (i = 0; i < last; i++)
		{
			if (array[i + 1] < array[i])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
}
