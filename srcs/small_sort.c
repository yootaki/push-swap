#include "../includes/libft/libft.h"
#include "../includes/mylibft/mylibft.h"
#include "../includes/push_swap.h"

/* 乱数3つ以下のソート */
void	simple_sort(t_bclist *a)
{
	int	lst1;
	int	lst2;
	int	last;

	last = a->prev->num;
	lst1 = a->next->num;
	lst2 = a->next->next->num;
	if (lst1 > lst2 && lst2 < last && last > lst1)
		sa(a, PS);
	else if (lst1 > lst2 && lst2 > last && last < lst1)
	{
		sa(a, PS);
		rra(a, PS);
	}
	else if (lst1 > last && lst1 > lst2 && lst2 < last)
		ra(a, PS);
	else if (lst1 < last && lst1 < lst2 && lst2 > last)
	{
		sa(a, PS);
		ra(a, PS);
	}
	else if (lst1 < lst2 && lst2 > last && lst1 > last)
		rra(a, PS);
}

void	get_min_num(t_bclist *a, t_bclist *b, t_bclist *tmp, int a_size)
{
	int	min;
	int	n;
	int	i;

	min = a->next->num;
	tmp = a->next;
	n = 1;
	i = 0;
	while (++i <= a_size)
	{
		if (min > tmp->next->num && i < a_size)
		{
			min = tmp->next->num;
			n = i;
		}
		tmp = tmp->next;
	}
	while (tmp->next->num != min)
	{
		if (n <= a_size / 2)
			ra(tmp, PS);
		else
			rra(tmp, PS);
	}
	pb(tmp->next, b, PS);
}

void	usually_sort(t_bclist *a, t_bclist *b)
{
	t_bclist	*tmp;
	int			a_size;

	tmp = NULL;
	a_size = ft_bclstsize(a);
	while (a_size > 3)
	{
		get_min_num(a, b, tmp, a_size);
		a_size--;
	}
	simple_sort(a);
	while (b->next != b)
	{
		tmp = b->next;
		pa(a, tmp, PS);
	}
}

void	small_sort(int argc, t_bclist *a, t_bclist *b)
{
	if (argc == 3 && \
	ft_issmall(a->next->num, a->next->next->num))
		sa(a, PS);
	else if (argc == 4)
		simple_sort(a);
	else if (argc <= 6)
		usually_sort(a, b);
}
