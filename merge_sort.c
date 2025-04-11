#include "push_swap.h"

int	*list_to_arr(t_list* head, int size)
{
	int i;
	int	*arr;

	arr = malloc((size) * sizeof(int));
	if (arr == NULL)
		free_all_exit(1);
	i = 0;
	while (head)
	{
		arr[i++] = *(int*)head->content;
		head = head->next;
	}
	return (arr);
}
void swap(int* a, int* b)
{
    int temp;

	temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int	pivot;
    int i;
	int	j;
 	
	pivot = arr[high];
 	i = low - 1;
	j = low;
    while (j < high)
	{
        if (arr[j] <= pivot)
		{
            i++;
            swap(&arr[i], &arr[j]);
        }
		j++;
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(int arr[], int low, int high)
{
    int pivot_index;

    if (low < high)
	{
		pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr,  pivot_index + 1, high);
    }
}
