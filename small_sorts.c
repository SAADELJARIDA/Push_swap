/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:24:58 by sel-jari          #+#    #+#             */
/*   Updated: 2025/04/12 11:25:00 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(void)
{
	t_list	*temp;

	temp = gv_a()->head;
	while (temp->next)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	sort_3(void)
{
	int	head;
	int	second;
	int	third;

	if (is_sorted())
		return ;
	head = *(int *)gv_a()->head->content;
	second = *(int *)gv_a()->head->next->content;
	third = *(int *)gv_a()->head->next->next->content;
	if (head < second && head < third && second > third)
	{
		sa();
		rr();
	}
	if (head > second && head < third && second < third)
		sa();
	if (head < second && head > third && second > third)
		rra();
	if (head > second && head > third && second < third)
		ra();
	if (head > second && head > third && second > third)
	{
		sa();
		rra();
	}
}

void	sa_ra_sa_rra(void)
{
	sa();
	ra();
	sa();
	rra();
}

void	sort_4(void)
{
	int	head;
	int	second;
	int	tail;
	int	third;

	if (is_sorted())
		return ;
	pb();
	sort_3();
	pa();
	head = *(int *)gv_a()->head->content;
	second = *(int *)gv_a()->head->next->content;
	third = *(int *)gv_a()->head->next->next->content;
	tail = *(int *)gv_a()->tail->content;
	if (second > head)
		return ;
	else if (tail < head)
		ra();
	else if (head > second && third > head)
		sa();
	else
		sa_ra_sa_rra();
}

void	sort_5(void)
{
	t_sp	sp;
	int		*arr;

	arr = list_to_arr(gv_a()->head, gv_a()->size);
	quick_sort(arr, 0, gv_a()->size - 1);
	find2_mins(arr[0]);
	find2_mins(arr[1]);
	sort_3();
	pa();
	pa();
	sp.head = *(int *)gv_a()->head->content;
	sp.second = *(int *)gv_a()->head->next->content;
	sp.third = *(int *)gv_a()->head->next->next->content;
	sp.fourth = *(int *)gv_a()->head->next->next->next->content;
	sp.tail = *(int *)gv_a()->tail->content;
	if (sp.head < sp.second)
		return ;
	if (sp.head > sp.tail)
		ra();
	if (sp.head > sp.second && sp.head < sp.third)
		sa();
	if (sp.head > sp.third && sp.head < sp.fourth)
		sa_ra_sa_rra();
	free(arr);
}
