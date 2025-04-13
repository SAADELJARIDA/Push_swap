/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:34:38 by sel-jari          #+#    #+#             */
/*   Updated: 2025/04/10 00:34:39 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;

	if (ac == 1)
		return (0);
	a = norm_arg(ac, av);
	if (is_sorted())
	{
		free_all_exit(0);
		return (0);
	}
	if (a->size == 2)
		sa();
	if (a->size == 3)
		sort_3();
	if (a->size == 4)
		sort_4();
	if (a->size == 5)
		sort_5();
	else
	{
		push_to_b();
		push_to_a(&gv_a()->head, &gv_b()->head);
	}
	free_all_exit(0);
}
