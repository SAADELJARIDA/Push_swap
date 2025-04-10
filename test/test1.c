#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

// Node structure
typedef struct s_list
{
    int value;
    struct s_list *next;
} t_list;

// Function to find the middle and split the list
void split_list(t_list *source, t_list **front, t_list **back)
{
    t_list *slow;
    t_list *fast;

    slow = source;
    fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

// Merge two sorted lists
t_list *merge_sorted_lists(t_list *a, t_list *b)
{
    t_list *result = NULL;

    if (!a)
        return b;
    if (!b)
        return a;

    if (a->value <= b->value)
    {
        result = a;
        result->next = merge_sorted_lists(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge_sorted_lists(a, b->next);
    }

    return result;
}

// Merge Sort function
void merge_sort(t_list **head_ref)
{
    t_list *head = *head_ref;
    t_list *a;
    t_list *b;

    if (!head || !head->next)
        return;

    // Split the list
    split_list(head, &a, &b);

    // Recursively sort
    merge_sort(&a);
    merge_sort(&b);

    // Merge the sorted lists
    *head_ref = merge_sorted_lists(a, b);
}


// Utility: Create a new node
t_list *new_node(int value)
{
    t_list *node = malloc(sizeof(t_list));
    node->value = value;
    node->next = NULL;
    return node;
}

// Utility: Append node to list
void append_node(t_list **head, int value)
{
    t_list *new = new_node(value);
    if (!*head)
    {
        *head = new;
        return;
    }
    t_list *temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}

// Utility: Print list
void print_list(t_list *head)
{
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

// Main to test
int main(void)
{
    t_list *list = NULL;

    // Add test values (unordered)
    append_node(&list, 42);
    append_node(&list, 3);
    append_node(&list, 17);
    append_node(&list, 8);
    append_node(&list, 25);
    append_node(&list, 123);
    append_node(&list, 1417);
    append_node(&list, 812);
    append_node(&list, 252);

    printf("Before sorting:\n");
    print_list(list);

    merge_sort(&list);

    printf("After sorting:\n");
    print_list(list);

    return 0;
}


