/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootaki <yootaki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:43:23 by yootaki           #+#    #+#             */
/*   Updated: 2021/10/05 11:43:24 by yootaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibft.h"

static void	ft_swap(int *x, int i, int j)
{
	int	tmp;

	tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}

void	my_quick_sort(int *x, int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right;
	pivot = x[(left + right) / 2];
	while (1)
	{
		while (x[i] < pivot)
			i++;
		while (pivot < x[j])
			j--;
		if (i >= j)
			break ;
		ft_swap(x, i, j);
		i++;
		j--;
	}
	if (left < i - 1)
		my_quick_sort(x, left, i - 1);
	if (j + 1 < right)
		my_quick_sort(x, j + 1, right);
}
