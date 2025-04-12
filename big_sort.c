/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:59:47 by sel-jari          #+#    #+#             */
/*   Updated: 2025/04/12 23:59:48 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load_range(void)
{
	int		size;
	t_cont	*cont;

	cont = gv_cont();
	size = gv_a()->size;
	if (size > 5 && size < 100)
		cont->end = size / 5;
	if (size > 100 && size <= 500)
		cont->end = size / 12;
}

void	update_range(int *start, int *end, int size)
{
	if (*start < *end - 1)
		(*start)++;
	if (*end < size - 1)
		(*end)++;
}

void	b_stack_condition(t_list *head)
{
	int	value1;
	int	value2;

	if (head->next == NULL)
		return ;
	value1 = *(int *)head->content;
	value2 = *(int *)head->next->content;
	if (value1 < value2)
		sb();
}

void	push_to_b(void)
{
	int		*arr;
	int		value;

	arr = list_to_arr(gv_a()->head, gv_a()->size);
	quick_sort(arr, 0, gv_a()->size - 1);
	load_range();
	while (gv_a()->head)
	{
		value = *(int *)gv_a()->head->content;
		if (arr[gv_cont()->start] < value && arr[gv_cont()->end] >= value)
		{
			pb();
			b_stack_condition(gv_b()->head);
			update_range(&gv_cont()->start, &gv_cont()->end, gv_a()->size);
		}
		else if (value <= arr[gv_cont()->start])
		{
			pb();
			rb();
			update_range(&gv_cont()->start, &gv_cont()->end, gv_a()->size);
		}
		else
			ra();
	}
	free(arr);
}
