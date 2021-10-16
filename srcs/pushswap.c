/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootaki <yootaki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:43:51 by yootaki           #+#    #+#             */
/*   Updated: 2021/10/16 21:27:43 by yootaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_dclist	*stack_a;
	t_dclist	*stack_b;
	int			*nums;

	if (argc == 1)
		return (0);
	stack_a = ft_bclstnew(NULL);
	stack_b = ft_bclstnew(NULL);
	nums = (int *)malloc(sizeof(int) * (argc - 1));
	if (init_stack(argc, argv, stack_a, nums))
		ps_error_print(stack_a, stack_b, nums);
	if (!check_sort(stack_a, stack_b))
	{
		ps_free_all(stack_a, stack_b, nums);
		return (0);
	}
	else
		my_quick_sort(nums, 0, argc - 2);
	if (argc < 7)
		small_sort(argc, stack_a, stack_b);
	else
		big_sort(stack_a, stack_b, nums);
	ps_free_all(stack_a, stack_b, nums);
	return (0);
}
