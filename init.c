/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:33:41 by sel-jari          #+#    #+#             */
/*   Updated: 2025/04/10 00:33:47 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
t_move *gv_move(void)
{
	static t_move;

	return (&t_move);
}
 */
t_stack	*gv_a(void)
{
	static t_stack	a;

	return (&a);
}

t_stack	*gv_b(void)
{
	static t_stack	b;

	return (&b);
}

char	***gv_arr(void)
{
	static char	**arr;

	return (&arr);
}
