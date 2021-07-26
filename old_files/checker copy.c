#include "../includes/get_next_line/get_next_line.h"
#include "../includes/mylibft/mylibft.h"
#include "../includes/push_swap.h"

/* aがソートされているか & bが空か */
int	check_sort(t_bclist *a ,t_bclist *b)
{
	t_bclist	*lst;

	lst = a->next;
	/* aがソートされているか */
	while (lst != a)
	{
		if (lst->num > lst->next->num && lst->next != a)
			return (1);
		lst = lst->next;
	}
	/* bが空になっているか */
	if (ft_bclstsize(b))
		return (1);
	return (0);
}

int	strlen_ps(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

/* 読み込んだコマンドとコマンドが一致しているか確認 */
int	strncmp_ps(const char *s1, const char *s2)
{
	int	i;

	if (strlen_ps(s1) != strlen_ps(s2))
		return (1);
	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

/* コマンドを数値に変換して配列に格納 */
int	cmd_proc(t_bclist *a, t_bclist *b, char *cmd)
{
	if (!strncmp_ps(cmd, "sa\n"))
		return (sa(a, CH));
	else if (!strncmp_ps(cmd, "sb\n"))
		return (sb(b, CH));
	else if (!strncmp_ps(cmd, "ss\n"))
		return (ss(a, b, CH));
	else if (!strncmp_ps(cmd, "ra\n"))
		return (ra(a, CH));
	else if (!strncmp_ps(cmd, "rb\n"))
		return (rb(b, CH));
	else if (!strncmp_ps(cmd, "rr\n"))
		return (rr(a, b, CH));
	else if (!strncmp_ps(cmd, "rra\n"))
		return (rra(a, CH));
	else if (!strncmp_ps(cmd, "rrb\n"))
		return (rrb(b, CH));
	else if (!strncmp_ps(cmd, "rrr\n"))
		return (rrr(a, b, CH));
	else if (!strncmp_ps(cmd, "pa\n"))
		return (pa(a, b->next, CH));
	else if (!strncmp_ps(cmd, "pb\n"))
		return (pb(a->next, b, CH));
	else
		return (1);
}

int	main(int argc, char **argv)
{
	t_bclist	*stack_a;
	t_bclist	*stack_b;

	/* 番兵ノードを作成 */
	stack_a = ft_bclstnew(0);
	stack_b = ft_bclstnew(0);
	/* コマンドライン引数の確認とスタックの初期化 */
	if (argc == 1)
		return (1);
	if (init_stack(argc, argv, stack_a, NULL))
	{
		write(2, "Error\n", 6);
		return (1);
	}

	/* GNLで読みこむ(get_cmdとか名前の関数にする) */
	//返り値1がまだ読み込み、0がEOF
	char	*cmd;
	while (get_next_line(0, &cmd) > 0)
	{
		//もしエラー(1)が帰ってきたら終了
		if (cmd_proc(stack_a, stack_b, cmd))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		free(cmd);
	}
	if (*cmd != '\0')
	{
		free(cmd);
		write(2, "Error\n", 6);
		return (1);
	}
	/* ソートされているかチェック */
	if (!check_sort(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "K0\n", 3);
	return (0);
}
