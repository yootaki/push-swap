/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootaki <yootaki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:43:44 by yootaki           #+#    #+#             */
/*   Updated: 2021/10/16 21:47:59 by yootaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ss(t_dclist *a, t_dclist *b, int type)
{
	if (type == PS)
		write(1, "ss\n", 3);
	if (sa(a, type) || sb(b, type))
		return (1);
	return (0);
}

int	rr(t_dclist *a, t_dclist *b, int type)
{
	if (type == PS)
		write(1, "rr\n", 3);
	if (ra(a, type) || rb(b, type))
		return (1);
	return (0);
}

int	rrr(t_dclist *a, t_dclist *b, int type)
{
	if (type == PS)
		write(1, "rrr\n", 4);
	if (rra(a, type) || rrb(b, type))
		return (1);
	return (0);
}
