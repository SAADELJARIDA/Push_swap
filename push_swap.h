/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:31:14 by sel-jari          #+#    #+#             */
/*   Updated: 2025/04/10 00:31:21 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	t_list	*head;
	int		size;
	t_list	*tail;
	char	*name;
}			t_stack;

typedef struct s_cont
{
	int	mid;
	int	offset;
	int	start;
	int	end;
}			t_cont;

t_stack	*gv_a(void);
t_stack	*gv_b(void);
t_cont	*gv_cont(void);
char	***gv_arr(void);

void	ft_exit(int status);
void	free_arr(char **arr);
void	error_if_duplicate(t_stack *a, int num);
void	free_all_exit(int status);

char	**normalize_input_args(int ac, char **av);
t_stack	*load_a(int ac, char **av);

void	swap(t_stack *stack);
void	push(t_stack *stack_to_push, t_stack *take_elemt);
void	rotate(t_stack *stack);
void	r_rotate(t_stack *stack);

int		*list_to_arr(t_list *head, int size);
void	quick_sort(int *arr, int low, int high);

t_stack	*norm_arg(int ac, char **av);

void	sa(void);
void	pa(void);
void	ra(void);
void	rra(void);

void	ss(void);
void	rr(void);
void	rrr(void);

void	sb(void);
void	pb(void);
void	rb(void);
void	rrb(void);

int		is_sorted(void);
void	sort_3(void);
void	sort_4(void);
void	sort_5(void);

void	load_range(void);

void	push_to_b();
#endif
