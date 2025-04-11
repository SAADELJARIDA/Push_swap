#include "push_swap.h"

void split_list(t_list *source, t_list **front, t_list **back, int mid) {
	t_list *current;
	int count;

	count = 0;
	*current = source
	while (count < mid - 1 && current != NULL) 
	{
		current = current->next;
		count++;
	}
	*front = source;
	*back = current->next;
	current->next = NULL;
}

t_list *merge_sorted_lists(t_list *a, t_list *b)
{
	t_list dummy;
	t_list *tail;

	dummy.next = NULL;
	tail = &dummy;
	while (a != NULL && b != NULL)
	{
		if (a->value <= b->value)
		{
			tail->next = a;
			a = a->next;
		}
		else
		{
			tail->next = b;
			b = b->next;
		}
		tail = tail->next;
	}
 

	if (a != NULL)
		tail->next = a;
	else
		tail->next = b;

	return dummy.next;
}

t_list *merge_sort(t_list *head, int size)
{
	t_list *front;
	t_list *back;
	int		mid;

	mid = size / 2;
	if (head == NULL || head->next == NULL)
		return (head);

	// Split the list into two halves
	split_list(head, &front, &back, mid);

	// Recursively sort the front and back
	front = merge_sort(front, mid);
	back = merge_sort(back, size - mid);

	// Merge the sorted halves
	return merge_sorted_lists(front, back);
}
