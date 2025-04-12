#include "push_swap.h"

void	sort_3(void)
{
	int	head;
	int	second;
	int	third;

	head = *(int *)gv_a()->head->content;
	second = *(int *)gv_a()->head->next->content;
	third = *(int *)gv_a()->head->next->next->content;
	if (head < second && head < third && second > third)
	{
		sa();
		rr();
	}
	if (head > second && head < third && second < third)
		sa();
	if (head < second && head > third && second > third)
		rra();
	if (head > second && head > third && second < third)
		ra();
	if (head > second && head > third && second > third)
	{
		sa();
		rra();
	}
}

void	sort_4(void)
{
	int	head;
	int	second;
	int	tail;

	pb();
	sort_3();
	pa();
	head = *(int *)gv_a()->head->content;
	second = *(int *)gv_a()->head->next->content;
	tail = *(int *)gv_a()->tail->content;
	if (second < head)
		return ;
	else if (tail < head)
		ra();
	else if (second < head && head < tail)
		sa();
	else
	{
		ra();
		sa();
		ra();
	}
}
