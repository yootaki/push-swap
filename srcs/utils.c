/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootaki <yootaki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:43:59 by yootaki           #+#    #+#             */
/*   Updated: 2021/10/16 21:01:48 by yootaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_free_all(t_bclist *a, t_bclist *b, int *nums)
{
	lst_free(a);
	lst_free(b);
	free(nums);
}

void	ch_free_all(t_bclist *a, t_bclist *b, int *nums, char *cmd)
{
	lst_free(a);
	lst_free(b);
	free(nums);
	free(cmd);
}

void	ps_error_print(t_bclist *a, t_bclist *b, int *nums)
{
	lst_free(a);
	lst_free(b);
	free(nums);
	write(2, "Error\n", 6);
	exit(1);
}

void	ch_error_print(t_bclist *a, t_bclist *b, int *nums, char *cmd)
{
	lst_free(a);
	lst_free(b);
	free(nums);
	free(cmd);
	write(2, "Error\n", 6);
	exit(1);
}
