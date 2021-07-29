#include "../includes/libft/libft.h"
#include "../includes/mylibft/mylibft.h"
#include "../includes/push_swap.h"

t_bclist	*ft_bclstnew(int num)
{
	t_bclist	*lst;

	lst = (t_bclist *)malloc(sizeof(t_bclist));
	if (lst == NULL)
		return (NULL);
	lst->prev = lst;
	lst->next = lst;
	lst->num = num;
	return (lst);
}

void	ft_bclstadd_back(t_bclist *top, t_bclist *new)
{
	t_bclist	*last;

	if (top == NULL || new == NULL)
		return ;
	last = top->prev;
	top->prev = new;
	last->next = new;
	new->prev = last;
	new->next = top;
}

int	ft_bclstsize(t_bclist *lst)
{
	int			count;
	t_bclist	*sentinel;

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

void	lst_free(t_bclist *lst)
{
	t_bclist	*tmp;
	int			n;

	n = ft_bclstsize(lst);
	while (n-- >= 0)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}
