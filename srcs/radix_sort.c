/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootaki <yootaki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:43:54 by yootaki           #+#    #+#             */
/*   Updated: 2021/10/05 11:43:55 by yootaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/mylibft/mylibft.h"
#include "../includes/push_swap.h"

void	make_stack_simple(t_bclist *a, int *nums, int n)
{
	t_bclist	*tmp;
	int			i;
	int			j;

	tmp = a->next;
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			if (tmp->num == nums[j])
			{
				tmp->num = j;
				break ;
			}
		}
		tmp = tmp->next;
	}
}

void	my_radix_sort(t_bclist *a, t_bclist *b, int max_bit, int n)
{
	t_bclist	*tmp_a;
	t_bclist	*tmp_b;
	int			i;
	int			j;

	i = -1;
	while (++i < max_bit)
	{
		n = ft_bclstsize(a);
		j = -1;
		while (++j < n)
		{
			tmp_a = a->next;
			if (((tmp_a->num >> i) & 1) == 1)
				ra(a, PS);
			else
				pb(tmp_a, b, PS);
		}
		tmp_b = b->next;
		while (tmp_b != b)
		{
			tmp_b = tmp_b->next;
			pa(a, tmp_b->prev, PS);
		}
	}
}

void	big_sort(t_bclist *a, t_bclist *b, int *nums)
{
	int	max_num;
	int	max_bit;
	int	n;

	n = ft_bclstsize(a);
	make_stack_simple(a, nums, n);
	max_num = n - 1;
	max_bit = 0;
	while (max_num >> max_bit != 0)
		max_bit++;
	my_radix_sort(a, b, max_bit, n);
}
