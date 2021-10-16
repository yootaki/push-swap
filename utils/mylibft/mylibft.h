/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylibft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootaki <yootaki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:44:48 by yootaki           #+#    #+#             */
/*   Updated: 2021/10/05 11:44:49 by yootaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIBFT_H
# define MYLIBFT_H

# include "../libft/libft.h"

void	my_quick_sort(int *x, int left, int right);
int		ft_islarge(int a, int b);
int		ft_issmall(int a, int b);
double	ft_atof(char *s);

#endif
