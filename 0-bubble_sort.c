#include "sort.h"
/**
 * bubble_sort - Doubly linked list node
 *
 * @array: Integer stored in the node
 * @size: Pointer to the previous element of the list
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, c = 0, flag = 0;
	int temp = 0;

	if (array == NULL)
		return;
	while (c == 0)
	{
		flag = 0;
		for (i = 0; i < size; i++)
		{
			if (array[i + 1] < array[i] && i < size - 1)
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
				flag = 1;
			}
			if (i == size - 1 && flag == 0)
				c = 1;
		}
	}
}
