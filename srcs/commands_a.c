/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootaki <yootaki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:43:39 by yootaki           #+#    #+#             */
/*   Updated: 2021/10/16 21:01:27 by yootaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sa(t_bclist *a, int type)
{
	int	tmp;

	if (type == PS)
		write(1, "sa\n", 3);
	if (a->next->next == a || a->next == NULL)
		return (1);
	tmp = a->next->num;
	a->next->num = a->next->next->num;
	a->next->next->num = tmp;
	return (0);
}

int	ra(t_bclist *a, int type)
{
	t_bclist	*a_last;
	t_bclist	*a_top;
	t_bclist	*tmp;

	if (type == PS)
		write(1, "ra\n", 3);
	if (a == NULL)
		return (1);
	else if (a->next == a || a->next->next == a)
		return (0);
	a_last = a->prev;
	a_top = a->next;
	tmp = a_top->next;
	a_last->next = a_top;
	a_top->prev = a_last;
	a_top->next = a;
	a->prev = a_top;
	a->next = tmp;
	tmp->prev = a;
	return (0);
}

int	rra(t_bclist *a, int type)
{
	t_bclist	*a_last;
	t_bclist	*a_top;
	t_bclist	*tmp;

	if (type == PS)
		write(1, "rra\n", 4);
	if (a == NULL)
		return (1);
	else if (a->next == a || a->next->next == a)
		return (0);
	a_last = a->prev;
	a_top = a->next;
	tmp = a_last->prev;
	a_top->prev = a_last;
	a_last->next = a_top;
	a_last->prev = a;
	a->next = a_last;
	a->prev = tmp;
	tmp->next = a;
	return (0);
}

int	pb(t_bclist *a, t_bclist *b, int type)
{
	t_bclist	*a_top;
	t_bclist	*b_top;
	t_bclist	*tmp;

	if (type == PS)
		write(1, "pb\n", 3);
	if (a == NULL || b == NULL)
		return (1);
	else if (a->next == a)
		return (0);
	a_top = a;
	b_top = b->next;
	tmp = a_top->next;
	a->prev->next = tmp;
	tmp->prev = a->prev;
	b_top->prev = a_top;
	a_top->next = b_top;
	a_top->prev = b;
	b->next = a_top;
	return (0);
}
