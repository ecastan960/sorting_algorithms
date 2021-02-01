#include "sort.h"
/**
 * bubble_sort - Doubly linked list node
 *
 * @array: Integer stored in the node
 * @size: Pointer to the previous element of the list
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, last = size;
	int temp = 0;

	while (i < last - 1)
	{
		if (array[i + 1] < array[i])
		{
			temp = array[i + 1];
			array[i + 1] = array[i];
			array[i] = temp;
			if (i + 1 == last - 1)
			{
				last--;
				i = 0;
			}
			else
				i++;
			print_array(array, size);
		}
		else
			i++;
	}
}
