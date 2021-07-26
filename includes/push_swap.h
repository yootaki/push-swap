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

/* スタックを初期化 */
int	init_stack(int argc, char **argv, t_bclist *a, int *nums);

/* リスト系関数 */
t_bclist	*ft_bclstnew(int num);
void		ft_bclstadd_back(t_bclist *top, t_bclist *new);
int			ft_bclstsize(t_bclist *lst);
void		lst_free(t_bclist *lst);

/* エラー */
void	ps_error_print(t_bclist *a, t_bclist *b);
void	ch_error_print(t_bclist *a, t_bclist *b, char *cmd);

/* コマンド */
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
