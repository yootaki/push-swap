/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootaki <yootaki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:43:48 by yootaki           #+#    #+#             */
/*   Updated: 2021/10/16 22:33:28 by yootaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dclist	*ft_dclstnew(void *content)
{
	t_dclist	*lst;

	lst = (t_dclist *)malloc(sizeof(t_dclist));
	if (lst == NULL)
		return (NULL);
	lst->prev = lst;
	lst->next = lst;
	lst->content = content;
	return (lst);
}

void	ft_dclstadd_back(t_dclist *top, t_dclist *new)
{
	t_dclist	*last;

	if (top == NULL || new == NULL)
		return ;
	last = top->prev;
	top->prev = new;
	last->next = new;
	new->prev = last;
	new->next = top;
}

int	ft_dclstsize(t_dclist *lst)
{
	int			count;
	t_dclist	*sentinel;

	if (lst == NULL)
		return (0);
	count = 0;
	sentinel = lst;
	lst = lst->next;
	while (lst != sentinel)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	dclst_free(t_dclist *lst)
{
	t_dclist	*tmp;

	tmp = lst->next;
	while (tmp->content != NULL)
	{
		free(tmp);
		tmp = tmp->next;
	}
	free(lst);
}
