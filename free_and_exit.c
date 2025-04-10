/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:33:26 by sel-jari          #+#    #+#             */
/*   Updated: 2025/04/10 00:33:33 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
	*gv_arr() = NULL;
}

void	ft_exit(int status)
{
	if (status)
	{
		write(2, "Error\n", 6);
		exit(status);
	}
	exit(status);
}

void	del(void *content)
{
	free(content);
}

void	free_all_exit(int status)
{
	if (*gv_arr() != NULL)
		free_arr(*gv_arr());
	ft_lstclear(&(gv_a()->head), del);
	ft_exit(status);
}

void	error_if_duplicate(t_stack *a, int num)
{
	t_list	*temp;

	temp = a->head;
	while (temp != NULL)
	{
		if (*(int *)temp->content == num)
			free_all_exit(1);
		temp = temp->next;
	}
}
