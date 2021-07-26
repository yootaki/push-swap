#include "../includes/get_next_line/get_next_line.h"
#include "../includes/mylibft/mylibft.h"
#include "../includes/push_swap.h"

void	lst_free(t_bclist *lst)
{
	t_bclist	*tmp;
	int	n;

	n = ft_bclstsize(lst);
	while (n-- >= 0)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	ps_error_print(t_bclist *a, t_bclist *b)
{
	lst_free(a);
	lst_free(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	ch_error_print(t_bclist *a, t_bclist *b, char *cmd)
{
	lst_free(a);
	lst_free(b);
	free(cmd);
	write(2, "Error\n", 6);
	exit(1);
}
