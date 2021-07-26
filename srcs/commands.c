#include "../includes/libft/libft.h"
#include "../includes/mylibft/mylibft.h"
#include "../includes/push_swap.h"

int	ss(t_bclist *a, t_bclist *b, int type)
{
	if (type == PS)
		write(1, "ss\n", 3);
	if (sa(a, type) || sb(b, type))
		return (1);
	return (0);
}

int	rr(t_bclist *a, t_bclist *b, int type)
{
	if (type == PS)
		write(1, "rr\n", 3);
	if(ra(a, type) || rb(b, type))
		return (1);
	return (0);
}

int	rrr(t_bclist *a, t_bclist *b, int type)
{
	if (type == PS)
		write(1, "rrr\n", 4);
	if (rra(a, type) || rrb(b, type))
		return (1);
	return (0);
}
