/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:58:52 by sel-jari          #+#    #+#             */
/*   Updated: 2025/04/12 23:58:54 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_index(t_list *head)
{
	int	max;
	int	i;
	int	i_max;

	max = *(int *)head->content;
	i = 0;
	i_max = 0;
	while (head)
	{
		if (*(int *)head->content > max)
		{
			max = *(int *)head->content;
			i_max = i;
		}
		head = head->next;
		i++;
	}
	return (i_max);
}

int	min_index(t_list *head)
{
	int	min;
	int	i;
	int	i_min;

	min = *(int *)head->content;
	i = 0;
	i_min = 0;
	while (head)
	{
		if (*(int *)head->content < min)
		{
			min = *(int *)head->content;
			i_min = i;
		}
		head = head->next;
		i++;
	}
	return (i_min);
}

void	push_to_a(t_list **head_a, t_list **head_b)
{
	while (*head_b)
	{
		if (max_index(*head_b) > (ft_lstsize(*head_b) / 2))
			while (max_index(*head_b) != 0)
				rrb();
		else
			while (max_index(*head_b) != 0)
				rb();
		pa();
	}
}

void	find2_mins(int min)
{
	if (min_index(gv_a()->head) < 2)
	{
		while (*(int *)gv_a()->head->content != min)
			ra();
	}
	else
	{
		while (*(int *)gv_a()->head->content != min)
			rra();
	}
	pb();
}
