#include "sort.h"
/**
 * bubble_sort - Doubly linked list node
 *
 * @array: Integer stored in the node
 * @size: Pointer to the previous element of the list
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, last = size - 1, j = 1;
	int temp, flag = 0;

	if (array <= 1 || size <= 1)
		return;

	while (last > 0)
	{
		while (j <= last)
		{
			if (array[j] < array[i])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
				flag = 1;
			}
			i++;
			j++;
		}
		if (flag == 0)
			return;
		flag = 0;
		last--;
		i = 0;
		j = 1;
	}
}
