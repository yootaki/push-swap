/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootaki <yootaki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:43:33 by yootaki           #+#    #+#             */
/*   Updated: 2021/10/16 23:22:42 by yootaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_duplicate(int *nums, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n - 1)
	{
		j = i;
		while (++j < n)
		{
			if (nums[i] == nums[j])
				return (1);
		}
	}
	return (0);
}

int	check_sort(t_dclist *a, t_dclist *b)
{
	t_dclist	*lst;

	lst = a->next;
	while (lst != a)
	{
		if (lst->content > lst->next->content && lst->next != a)
			return (1);
		lst = lst->next;
	}
	if (ft_bclstsize(b))
		return (1);
	return (0);
}

int	check_over(int sign, int num, int next_num)
{
	int	ov_div;
	int	ov_mod;

	num *= sign;
	if (sign == 1)
	{
		ov_div = INT_MAX / 10;
		ov_mod = INT_MAX % 10;
		if (ov_div < num || (ov_div == num && ov_mod < next_num))
			return (1);
	}
	else
	{
		ov_div = INT_MIN / 10;
		ov_mod = INT_MIN % 10 * (-1);
		if (ov_div > num || (ov_div == num && ov_mod < next_num))
			return (1);
	}
	return (0);
}

int	argv_isdigit(const char *str)
{
	int	i;
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	i = 0;
	if (str[i] == '\0')
		return (1);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (1);
		if (check_over(sign, num, str[i] - '0'))
			return (1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (0);
}

int	validate_args(int argc, char **argv)
{
	int	i;

	if (argc < 2 || argc > 1000)//??????1000???????????????
		return (1);
	i = 0;
	while (++i < argc)
	{
		if (argv_isdigit(argv[i]))
			return (1);
	}
	return (0);
}

int	init_stack(int argc, char **argv, t_dclist *a, t_dclist *b, int *nums)
{
	t_dclist	*tmp;
	int			i;

	a = ft_bclstnew(NULL);
	b = ft_bclstnew(NULL);
	nums = (int *)malloc(sizeof(int) * (argc - 1));
	if (!a || !b || !nums)
		return (1);
	i = 0;
	while (++i < argc)
		nums[i - 1] = ft_atoi(argv[i]);
	i = -1;
	while (++i < argc - 1)
	{
		tmp = ft_bclstnew(nums[i]);
		if (tmp == NULL)
			return (1);
		ft_bclstadd_back(a, tmp);
	}
	//?????????argv???strcmp??????validate??????????????????
	if (check_duplicate(nums, argc - 1))
		return (1);
	return (0);
}
