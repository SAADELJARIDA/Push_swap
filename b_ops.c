/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:32:40 by sel-jari          #+#    #+#             */
/*   Updated: 2025/04/10 00:32:46 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(void)
{
	swap(gv_b());
	write(1, "sb\n", 3);
}

void	pb(void)
{
	push(gv_b(), gv_a());
	write(1, "pb\n", 3);
}

void	rb(void)
{
	rotate(gv_b());
	write(1, "rb\n", 3);
}

void	rrb(void)
{
	r_rotate(gv_b());
	write(1, "rrb\n", 4);
}
