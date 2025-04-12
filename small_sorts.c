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
	int	head;
	int	second;
	int	third;
	int	fourth;
	int	tail;

	pb();
	sort_4();
	pa();
	head = *(int *)gv_a()->head->content;
	second = *(int *)gv_a()->head->next->content;
	third = *(int *)gv_a()->head->next->next->content;
	fourth = *(int *)gv_a()->head->next->next->next->content;
	tail = *(int *)gv_a()->tail->content;
	if (head < second)
		return ;
	if (head > tail)
		ra();
	if (head > second && head < third)
		sa();
	if (head > third && head < fourth)
		sa_ra_sa_rra();
	if (head > fourth && head < tail)
	{
		rra();
		sa();
		ra();
		ra();
	}
}
