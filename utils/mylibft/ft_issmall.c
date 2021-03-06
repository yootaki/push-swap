/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issmall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootaki <yootaki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:43:16 by yootaki           #+#    #+#             */
/*   Updated: 2021/10/16 23:36:01 by yootaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibft.h"

/* aとbを比較して小さい方の数字を返す */
void	*ft_issmall(void *a, void *b)
{
	if (a < b)
		return (a);
	else if (a > b)
		return (b);
	else
		return (a);
}
