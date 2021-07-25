#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../includes/libft/libft.h"

typedef struct s_bclist
{
	struct s_bclist	*prev;
	struct s_bclist	*next;
	int	num;
}t_bclist;

/* スタックを初期化 */
int	init_stack(int argc, char **argv, t_bclist *a, int *nums);

/* リスト系関数 */
t_bclist	*ft_bclstnew(int num);
void		ft_bclstadd_back(t_bclist *top, t_bclist *new);
int			ft_bclstsize(t_bclist *lst);

/* コマンド */
int	sa(t_bclist *a);
int	sb(t_bclist *b);
int	ss(t_bclist *a, t_bclist *b);
int	ra(t_bclist *a);
int	rb(t_bclist *b);
int	rr(t_bclist *a, t_bclist *b);
int	rra(t_bclist *a);
int	rrb(t_bclist *b);
int	rrr(t_bclist *a, t_bclist *b);
int	pa(t_bclist *a, t_bclist *b);
int	pb(t_bclist *a, t_bclist *b);
#endif
