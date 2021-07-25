#include "../includes/libft/libft.h"
#include "../includes/mylibft/mylibft.h"
#include "../includes/push_swap.h"

/* コマンドライン引数をスタックに格納 */
//malloc等失敗でreturn(1);
//基数ソート用のインデックス配列を作成&ソート
int	init_stack(int argc, char **argv, t_bclist *a, int *nums)
{
	t_bclist	*tmp;
	int	i;
	int	n;

	/* コマンドライン引数で受け取った数字をリストに格納 */
	n = 0;
	i = 0;
	while (++i < argc)
	{
		n = ft_atoi(argv[i]);
		if (nums != NULL)
			nums[i - 1] = n;
		tmp = ft_bclstnew(n);
		ft_bclstadd_back(a, tmp);
		if (tmp == NULL)
			return (1);
	}
	if (nums != NULL)
		my_quick_sort(nums, 0, argc - 2);
	return (0);
}

/* 新しいリストを作成 */
//numを格納、前後のポインタに自分自身を渡す
t_bclist	*ft_bclstnew(int num)
{
	t_bclist	*lst;

	lst = (t_bclist *)malloc(sizeof(t_bclist));
	if (lst == NULL)
		return ((void *)0);
	lst->prev = lst;
	lst->next = lst;
	lst->num = num;
	return (lst);
}

/* 新しいリストを既存のリストに追加 */
void	ft_bclstadd_back(t_bclist *top, t_bclist *new)
{
	t_bclist	*last;

	if (top == NULL || new == NULL)
		return ;
	//リストの最後を取得
	last = top->prev;
	//リストを連結
	top->prev = new;
	last->next = new;
	new->prev = last;
	new->next = top;
}

/* リストの数を数える */
int	ft_bclstsize(t_bclist *lst)
{
	int			count;
	t_bclist	*sentinel;

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
