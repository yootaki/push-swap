/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootaki <yootaki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:43:56 by yootaki           #+#    #+#             */
/*   Updated: 2021/10/16 23:33:13 by yootaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 乱数3つ以下のソート */
void	simple_sort(t_dclist *a)
{
	void	*lst1;
	void	*lst2;
	void	*last;

	last = a->prev->content;
	lst1 = a->next->content;
	lst2 = a->next->next->content;
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

void	get_min_num(t_dclist *a, t_dclist *b, t_dclist *tmp, int a_size)
{
	void	*min;
	int	n;
	int	i;

	min = a->next->content;
	tmp = a->next;
	n = 1;
	i = 0;
	while (++i <= a_size)
	{
		if (min > tmp->next->content && i < a_size)
		{
			min = tmp->next->content;
			n = i;
		}
		tmp = tmp->next;
	}
	while (tmp->next->content != min)
	{
		if (n <= a_size / 2)
			ra(tmp, PS);
		else
			rra(tmp, PS);
	}
	pb(tmp->next, b, PS);
}

void	usually_sort(t_dclist *a, t_dclist *b)
{
	t_dclist	*tmp;
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

void	small_sort(int argc, t_dclist *a, t_dclist *b)
{
	if (argc == 3 && \
	ft_issmall(a->next->content, a->next->next->content) == a->next->next->content)
		sa(a, PS);
	else if (argc == 4)
		simple_sort(a);
	else if (argc <= 6)
		usually_sort(a, b);
}
