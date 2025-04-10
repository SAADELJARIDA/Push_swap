/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:34:44 by sel-jari          #+#    #+#             */
/*   Updated: 2025/04/10 00:34:46 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_list	*temp;

	if (!stack->head || !stack->head->next)
		return ;
	temp = stack->head->next;
	stack->head->next = stack->head->next->next;
	temp->next = stack->head;
	stack->head = temp;
}

void	push(t_stack *stack_to_push, t_stack *stack_to_pop)
{
	t_list	*new;

	if (!stack_to_pop->head)
		return ;
	new = stack_to_pop->head;
	stack_to_pop->head = new->next;
	new->next = stack_to_push->head;
	stack_to_push->head = new;
}

void	rotate(t_stack *stack)
{
	t_list	*temp;

	if (!stack->head || !stack->head->next)
		return ;
	temp = stack->head->next;
	stack->tail->next = stack->head;
	stack->head->next = NULL;
	stack->head = temp;
	stack->tail = stack->tail->next;
}

void	r_rotate(t_stack *stack)
{
	t_list	*temp;

	if (!stack->head || !stack->head->next)
		return ;
	temp = stack->head;
	while (temp->next->next)
	{
		temp = temp->next;
	}
	stack->tail->next = stack->head;
	stack->head = stack->tail;
	stack->tail = temp;
	stack->tail->next = NULL;
}
