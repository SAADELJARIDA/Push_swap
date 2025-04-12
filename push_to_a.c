#include "push_swap.h"

static int	find_index(int	max)
{
	t_list	*temp;
	int	i;

	i = 0;
	temp = gv_b()->head;
	while (temp)
	{
		if (max == *(int *)temp->content)
			return (i);
		temp = temp->next;
	}
	return (0);
}
void	push_to_a(int *sorted_arr)
{
	int	i;
	int	max;
	int	size;

	size = gv_a()->size;
	max = sorted_arr[size - 1];
	while (gv_b()->head)
	{
		i = find_index(max);
		if (*(int *)gv_b()->head->content == max)
		{
			pa();
			max = sorted_arr[size--];
			return ;
		}
		else if (i < (size / 2 - 1))
		{
			while (*(int *)gv_b()->head->content != max)
				rb();
		}
		else if (i > (size / 2 - 1))
		{
			while (*(int *)gv_b()->head->content != max)
				rrb();
		}
	}
}
