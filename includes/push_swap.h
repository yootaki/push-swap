#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../includes/libft/libft.h"

# define PS 0
# define CH 1

typedef struct s_bclist
{
	struct s_bclist	*prev;
	struct s_bclist	*next;
	int	num;
}t_bclist;

/* args check */
int	check_sort(t_bclist *a, t_bclist *b);
int	check_duplicate(int *nums, int n);
int	check_over(int sign, int num, int next_num);
int	argv_isdigit(const char *str);
int	init_stack(int argc, char **argv, t_bclist *a, int *nums);

/* list func */
t_bclist	*ft_bclstnew(int num);
void		ft_bclstadd_back(t_bclist *top, t_bclist *new);
int			ft_bclstsize(t_bclist *lst);
void		lst_free(t_bclist *lst);

/* sort */
void	small_sort(int argc, t_bclist *a, t_bclist *b);
void	big_sort(t_bclist *a, t_bclist *b, int *nums);

/* error */
void	ps_error_print(t_bclist *a, t_bclist *b, int *nums);
void	ch_error_print(t_bclist *a, t_bclist *b, int *nums, char *cmd);

/* commands */
int	sa(t_bclist *a, int type);
int	sb(t_bclist *b, int type);
int	ss(t_bclist *a, t_bclist *b, int type);
int	ra(t_bclist *a, int type);
int	rb(t_bclist *b, int type);
int	rr(t_bclist *a, t_bclist *b, int type);
int	rra(t_bclist *a, int type);
int	rrb(t_bclist *b, int type);
int	rrr(t_bclist *a, t_bclist *b, int type);
int	pa(t_bclist *a, t_bclist *b, int type);
int	pb(t_bclist *a, t_bclist *b, int type);

#endif
