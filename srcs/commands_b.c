/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootaki <yootaki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:43:42 by yootaki           #+#    #+#             */
/*   Updated: 2021/10/16 21:47:26 by yootaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sb(t_dclist *b, int type)
{
	int	tmp;

	if (type == PS)
		write(1, "sb\n", 3);
	if (b->next->next == b || b->next == NULL)
		return (1);
	tmp = b->next->content;
	b->next->content = b->next->next->content;
	b->next->next->content = tmp;
	return (0);
}

int	rb(t_dclist *b, int type)
{
	t_dclist	*b_last;
	t_dclist	*b_top;
	t_dclist	*tmp;

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

int	rrb(t_dclist *b, int type)
{
	t_dclist	*b_last;
	t_dclist	*b_top;
	t_dclist	*tmp;

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

int	pa(t_dclist *a, t_dclist *b, int type)
{
	t_dclist	*a_top;
	t_dclist	*b_top;
	t_dclist	*tmp;

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
