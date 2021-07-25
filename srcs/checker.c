#include "../includes/get_next_line/get_next_line.h"
#include "../includes/mylibft/mylibft.h"
#include "../includes/push_swap.h"

/* リストをプリント */
void	bclst_print(t_bclist *a, t_bclist *b)
{
	int			a_size;
	int			b_size;
	t_bclist	*a_senti;
	t_bclist	*b_senti;

	a_size = ft_bclstsize(a);
	b_size = ft_bclstsize(b);
	a_senti = a;
	b_senti = b;
	a = a->next;
	b = b->next;
	while (a_size > b_size)
	{
		printf(" %11d            \n", a->num);
		a = a->next;
		a_size--;
	}
	while (b_size > a_size)
	{
		printf("            %11d \n", b->num);
		b = b->next;
		b_size--;
	}
	while (a_size > 0)
	{
		printf(" %11d %11d \n", a->num, b->num);
		a = a->next;
		b = b->next;
		a_size--;
	}
	printf(" ----------- ----------- \n");
	printf("      a           b      \n");
}

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
	if (b->prev != b && b->next != b)
		return (1);
	return (0);
}


/* 読み込んだコマンドとコマンドが一致しているか確認 */
int	strlen_ps(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}
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
	if (!strncmp_ps(cmd, "sa"))
		return (sa(a));
	else if (!strncmp_ps(cmd, "sb"))
		return (sb(b));
	else if (!strncmp_ps(cmd, "ss"))
		return (ss(a, b));
	else if (!strncmp_ps(cmd, "ra"))
		return (ra(a));
	else if (!strncmp_ps(cmd, "rb"))
		return (rb(b));
	else if (!strncmp_ps(cmd, "rr"))
		return (rr(a, b));
	else if (!strncmp_ps(cmd, "rra"))
		return (rra(a));
	else if (!strncmp_ps(cmd, "rrb"))
		return (rrb(b));
	else if (!strncmp_ps(cmd, "rrr"))
		return (rrr(a, b));
	else if (!strncmp_ps(cmd, "pa"))
		return (pa(a, b->next));
	else if (!strncmp_ps(cmd, "pb"))
		return (pb(a->next, b));
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

	/* リストをプリント */
	// bclst_print(stack_a, stack_b);

	/* ソートされているかチェック */
	// if (!check_sort(stack_a, stack_b))
	// 	printf("\nSort        : OK\n");

	/* メモリリークチェック */
	system("leaks checker");

	return (0);
}

/* ToDo */
//1. ランダムな数字を引数で受け取る
//argvで普通に受け取る

//2. スタックAとBを用意

//3. 標準入力上の命令を読みこむ
//readで1行ずつ読みこむ
//- enumでコマンドごとに数字を割り当てて配列とかにまとめる？と楽かも

//4. 全ての命令を読み込んだ後命令を実行
//読み込んだコマンドを順番に実行してスタックAをソートする

//5. ソートされているかの確認
//bが空かの確認
//okかkoを出す
