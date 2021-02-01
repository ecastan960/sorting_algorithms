#include "sort.h"
/**
 * selection_sort - Doubly linked list node
 *
 * @array: Integer stored in the node
 * @size: Pointer to the previous element of the list
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, c = 0, flag = 0;
	int temp_min = 0, temp_swap = 0;

	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			if (flag == 0)
			{
				temp_min = array[i];
				flag = 1;
			}
			if (array[j + 1] < temp_min && j < size - 1)
			{
				temp_min = array[j + 1];
				c = j + 1;
			}
		}
		if (temp_min != array[i])
		{
			temp_swap = array[i];
			array[i] = array[c];
			array[c] = temp_swap;
			print_array(array, size);
		}
		flag = 0;
	}
}
