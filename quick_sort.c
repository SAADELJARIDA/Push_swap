/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 03:13:00 by sel-jari          #+#    #+#             */
/*   Updated: 2025/04/11 03:13:02 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*list_to_arr(t_list *head, int size)
{
	int	i;
	int	*arr;

	arr = malloc(size * sizeof(int));
	if (arr == NULL)
		free_all_exit(1);
	i = 0;
	while (head)
	{
		arr[i++] = *(int *)head->content;
		head = head->next;
	}
	return (arr);
}

void	swap_element(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *arr, int low, int high)
{
	int pivot;
	int left;
	int right;

	right = high;
	left = low + 1;
	pivot = arr[low];

	while (left <= right)
	{
		while (left <= high && arr[left] < pivot)
			left++;
		while (right >= low && arr[right] > pivot)
			right--;
		if (left < right)
			swap_element(&arr[left], &arr[right]);
	}
	swap_element(&arr[low], &arr[right]);
	return right;
}

void	quick_sort(int *arr, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		quick_sort(arr, low, pivot_index - 1);
		quick_sort(arr, pivot_index + 1, high);
	}
}
