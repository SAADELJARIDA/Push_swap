/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:32:57 by sel-jari          #+#    #+#             */
/*   Updated: 2025/04/10 00:32:59 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(void)
{
	swap(gv_a());
	write(1, "sa\n", 3);
}

void	pa(void)
{
	push(gv_b(), gv_a());
	write(1, "pa\n", 3);
}

void	ra(void)
{
	rotate(gv_a());
	write(1, "ra\n", 3);
}

void	rra(void)
{
	r_rotate(gv_a());
	write(1, "rra\n", 4);
}
