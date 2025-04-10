/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:31:57 by sel-jari          #+#    #+#             */
/*   Updated: 2025/04/10 00:32:00 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(void)
{
	swap(gv_a());
	swap(gv_b());
	write(1, "ss\n", 3);
}

void	rr(void)
{
	rotate(gv_a());
	rotate(gv_b());
	write(1, "rr\n", 3);
}

void	rrr(void)
{
	r_rotate(gv_a());
	r_rotate(gv_b());
	write(1, "rrr\n", 3);
}
