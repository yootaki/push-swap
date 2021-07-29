#include "../includes/libft/libft.h"
#include "../includes/mylibft/mylibft.h"
#include "../includes/push_swap.h"

int	sb(t_bclist *b, int type)
{
	int	tmp;

	if (type == PS)
		write(1, "sb\n", 3);
	if (b->next->next == b || b->next == NULL)
		return (1);
	tmp = b->next->num;
	b->next->num = b->next->next->num;
	b->next->next->num = tmp;
	return (0);
}

int	rb(t_bclist *b, int type)
{
	t_bclist	*b_last;
	t_bclist	*b_top;
	t_bclist	*tmp;

	if (type == PS)
		write(1, "rb\n", 3);
	if (b == NULL)
		return (1);
	else if (b->next == b || b->next->next == b)
		return (0);
	b_last = b->prev;
	b_top = b->next;
	tmp = b_top->next;
	b_last->next = b_top;
	b_top->prev = b_last;
	b_top->next = b;
	b->prev = b_top;
	b->next = tmp;
	tmp->prev = b;
	return (0);
}

int	rrb(t_bclist *b, int type)
{
	t_bclist	*b_last;
	t_bclist	*b_top;
	t_bclist	*tmp;

	if (type == PS)
		write(1, "rrb\n", 4);
	if (b == NULL)
		return (1);
	else if (b->next == b || b->next->next == b)
		return (0);
	b_last = b->prev;
	b_top = b->next;
	tmp = b_last->prev;
	b_top->prev = b_last;
	b_last->next = b_top;
	b_last->prev = b;
	b->next = b_last;
	b->prev = tmp;
	tmp->next = b;
	return (0);
}

int	pa(t_bclist *a, t_bclist *b, int type)
{
	t_bclist	*a_top;
	t_bclist	*b_top;
	t_bclist	*tmp;

	if (type == PS)
		write(1, "pa\n", 3);
	if (a == NULL || b == NULL)
		return (1);
	else if (b->next == b)
		return (0);
	a_top = a->next;
	b_top = b;
	tmp = b_top->next;
	b->prev->next = tmp;
	tmp->prev = b->prev;
	a_top->prev = b_top;
	b_top->next = a_top;
	b_top->prev = a;
	a->next = b_top;
	return (0);
}
