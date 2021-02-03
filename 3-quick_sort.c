#include "sort.h"
/**
 * swap - Array sorting with quick sort method using lomuto
 *
 * @array: Integer stored in the node
 * @size: Size of array
 * @p_Less: Low value to swap
 * @p_greater: high value to swap
 */
void swap(int *array, int p_Less, int p_greater, size_t size)
{
	int temp;

	temp = array[p_greater];
	array[p_greater] = array[p_Less];
	array[p_Less] = temp;
	print_array(array, size);
}

/**
 * partition - Doubly linked list node
 *
 * @array: Integer stored in the node
 * @size: Size of array
 * @min: Low point of partition array
 * @last: High point of partition array
 * Return: New pivot position
 */

size_t partition(int *array, int min, int last, size_t size)
{
	int pivot = last, p_Less = min, p_greater = min, flag = 0, finish = 0;

	while ((pivot - min) >= 1 && finish == 0)
	{
		if (array[p_greater] > array[pivot])
		{
			while (array[p_Less] > array[pivot])
				p_Less++;
			if (p_Less < pivot)
			{
				swap(array, p_Less, p_greater, size);
			}
			else
			{
				swap(array, p_greater, pivot, size);
				flag = 1;
			}
		}
		if ((pivot - min) == 0)
			finish = 1;
		if (flag == 1 && pivot - p_greater > 2 && p_greater != 0)
			return (p_greater);
		if (p_greater == p_Less && p_greater == pivot && flag == 0)
		{
			p_greater = 0, p_Less = 0, flag = 0, pivot = pivot - 1;
			continue;
		}
		if (p_greater < pivot && flag != 1)
			p_greater++;
		p_Less++;
		if (flag == 1 && p_greater == 0)
			p_greater = min, p_Less = min, flag = 0;
		if (flag == 1 && p_greater > 0 && pivot - p_greater > 2)
			p_greater = min, p_Less = min, flag = 0, pivot = pivot - 1;
		if (flag == 1 && p_greater > 0)
			p_greater = min, p_Less = min, flag = 0;
	}
	return (pivot + 2);
}
/**
 * quick_sort - Array sorting with quick sort method using lomuto
 *
 * @array: Integer stored in the node
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	int min = 0, last = size - 1, pivot;

	if (min < last)
	{
		pivot = partition(array, min, last, size);
		partition(array, min, pivot - 1, size);
		partition(array, pivot + 1, last, size);
	}
}
