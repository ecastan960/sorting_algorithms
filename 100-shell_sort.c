#include "sort.h"
/**
 * swap - Array sorting with quick sort method using lomuto
 *
 * @array: Integer stored in the node
 * @i: Size of array
 * @j: high value to swap
 */
void swap(int *array, int i, int j)
{
	int temp;

	temp = array[j];
	array[j] = array[i];
	array[i] = temp;
}
/**
 * New_gap - Array sorting with quick sort method using lomuto
 *
 * @gap: Integer stored in the node
 * @count: Size of array
 * Return: New gap
 */
int New_gap(int gap, int count)
{
	int k;

	if (gap == 4)
		gap = 1;
	if (gap > 4)
	{
		gap = 1;
		for (k = 0; k < count - 1; k++)
			gap = gap * (3 + 1);
	}
	return (gap);
}

/**
 * shell_sort - Array sorting with quick sort method using lomuto
 *
 * @array: Integer stored in the node
 * @size: Size of array
 */
void shell_sort(int *array, size_t size)
{
	int i = 0, j = 0, flag = 0, gap = 1, new_gap = size;
	int count = 0, k, max = size - 1;

	if (array == NULL)
		return;
	while  (gap < new_gap)
	{
		gap = (gap * 3) + 1;
		count++;
	}
	gap = 1;
	for (k = 0; k < count - 1; k++)
		gap = (gap * 3) + 1;
	while (flag == 0)
	{
		j = gap + i;
		while (j <= max)
		{
			if (array[i] > array[j])
				swap(array, i, j);
			if (array[i] < array[i - gap])
			{
				while (i - gap >= 0)
				{
					if (array[i] < array[i - gap])
						swap(array, i, i - gap);
					i--, j--;
				}
			}
			i++, j++;
		}
		print_array(array, size);
		if (gap == 1)
			flag = 1;
		gap = New_gap(gap, count);
		if (gap >= 4)
			count--;
	}
}
