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
