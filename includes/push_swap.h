/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootaki <yootaki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:43:28 by yootaki           #+#    #+#             */
/*   Updated: 2021/10/16 23:26:51 by yootaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../utils/libft/libft.h"
# include "../utils/mylibft/mylibft.h"

# define PS 0
# define CH 1

typedef struct s_dclist
{
	struct s_dclist	*prev;
	struct s_dclist	*next;
	void			*content;
}t_dclist;

/* args check */
int			check_sort(t_dclist *a, t_dclist *b);
int			check_duplicate(int *nums, int n);
int			check_over(int sign, int num, int next_num);
int			argv_isdigit(const char *str);
int			validate_args(int argc, char **argv);
int			init_stack(int argc, char **argv, t_dclist *a, t_dclist *b, int *nums);

/* list func */
t_dclist	*ft_bclstnew(int num);
void		ft_bclstadd_back(t_dclist *top, t_dclist *new);
int			ft_bclstsize(t_dclist *lst);
void		lst_free(t_dclist *lst);

/* sort */
void		small_sort(int argc, t_dclist *a, t_dclist *b);
void		big_sort(t_dclist *a, t_dclist *b, int *nums);

/* commands */
int			sa(t_dclist *a, int type);
int			sb(t_dclist *b, int type);
int			ss(t_dclist *a, t_dclist *b, int type);
int			ra(t_dclist *a, int type);
int			rb(t_dclist *b, int type);
int			rr(t_dclist *a, t_dclist *b, int type);
int			rra(t_dclist *a, int type);
int			rrb(t_dclist *b, int type);
int			rrr(t_dclist *a, t_dclist *b, int type);
int			pa(t_dclist *a, t_dclist *b, int type);
int			pb(t_dclist *a, t_dclist *b, int type);

/* utils */
void		ps_free_all(t_dclist *a, t_dclist *b, int *nums);
void		ch_free_all(t_dclist *a, t_dclist *b, int *nums, char *cmd);
void		ps_error_print(t_dclist *a, t_dclist *b, int *nums);
void		ch_error_print(t_dclist *a, t_dclist *b, int *nums, char *cmd);

#endif
