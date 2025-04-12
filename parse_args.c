/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:34:24 by sel-jari          #+#    #+#             */
/*   Updated: 2025/04/10 00:34:33 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	better_atoi(char *str)
{
	int		sign;
	long	num;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (!*str)
			free_all_exit(1);
	}
	num = 0;
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		if (num * sign > 2147483647 || num * sign < -2147483648)
			free_all_exit(1);
		str++;
	}
	if (*str != '\0' && !ft_isdigit(*str))
		free_all_exit(1);
	return (num * sign);
}

static void	a_add_back(t_stack *a, int num)
{
	t_list	*new_node;
	int		*value;

	error_if_duplicate(a, num);
	value = malloc(sizeof(int));
	if (value == NULL)
		ft_exit(1);
	*value = num;
	new_node = ft_lstnew(value);
	if (new_node == NULL)
	{
		free(value);
		free_all_exit(1);
	}
	ft_lstadd_back(&(a->head), new_node);
}

t_stack	*norm_arg(int ac, char **av)
{
	t_stack	*a;
	char	**arr;
	int		i;
	t_list	*temp;

	i = 0;
	arr = normalize_input_args(ac, av);
	*gv_arr() = arr;
	if (arr == NULL)
		ft_exit(1);
	a = gv_a();
	if (a == NULL)
		free_all_exit(1);
	a->head = NULL;
	while (arr[i] != NULL)
		a_add_back(a, better_atoi(arr[i++]));
	temp = a->head;
	while (temp->next)
		temp = temp->next;
	gv_a()->tail = temp;
	gv_a()->size = i;
	free_arr(arr);
	return (a);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_list	*temp;
	t_stack	*b;

	if (ac == 1)
		return (0);
	a = norm_arg(ac, av);
	b = gv_b();
	temp = a->head;
	while (temp != NULL)
	{
		printf("%d\n", *(int *)temp->content);
		temp = temp->next;
	}
	printf("\n");
	if (a->size == 4)
		sort_4();
	b = NULL;
	temp = a->head;
	while (temp != NULL)
	{
		printf("%d\n", *(int *)temp->content);
		temp = temp->next;
	}
}
/*
*/
