#include "../libft/libft.h"
#include "../mylibft/mylibft.h"
#include "../get_next_line/get_next_line.h"
#include "push_swap.h"

//後で消す
#include <stdio.h>
int	order_count = 0;

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

/* 乱数3つ以下のソート */
void	simple_sort(t_bclist *a)
{
	int	lst1;
	int	lst2;
	int	last;

	last = a->prev->num;
	lst1 = a->next->num;
	lst2 = a->next->next->num;
	if (lst1 > lst2 && lst2 < last && last > lst1)
	{
		sa(a);
		order_count++;
	}
	else if (lst1 > lst2 && lst2 > last && last < lst1)
	{
		sa(a);
		rra(a);
		order_count += 2;
	}
	else if (lst1 > last && lst1 > lst2 && lst2 < last)
	{
		ra(a);
		order_count++;
	}
	else if (lst1 < last && lst1 < lst2 && lst2 > last)
	{
		sa(a);
		ra(a);
		order_count += 2;
	}
	else if (lst1 < lst2 && lst2 > last && lst1 > last)
	{
		rra(a);
		order_count++;
	}
}

/* aがソートされているかチェック */
int	check_sort(t_bclist *a)
{
	t_bclist	*lst;

	lst = a->next;
	while (lst != a)
	{
		if (lst->num > lst->next->num && lst->next != a)
			return (1);
		lst = lst->next;
	}
	return (0);
}

/* 乱数4つ以上6つ以下 */
void	usually_sort(t_bclist *a, t_bclist *b)
{
	int			a_size;
	int			min;
	int			n;
	int			i;
	t_bclist	*tmp;

	a_size = ft_bclstsize(a);
	n = 1;
	while (a_size > 3)
	{
		min = a->next->num;
		tmp = a->next;
		i = 1;
		while (i <= a_size)
		{
			if (min > tmp->next->num && i < a_size)
			{
				min = tmp->next->num;
				n = i;
			}
			tmp = tmp->next;
			i++;
		}
		while (tmp->next->num != min)
		{
			if (n >= a_size / 2)
				ra(tmp);
			else
				rra(tmp);
		}
		pb(tmp->next, b);
		order_count++;
		a_size--;
	}

	//aをソート
	simple_sort(a);

	// bからaに移動 & 数値の大小を確認
	while (b->next != b)
	{
		tmp = b->next;
		pa(a, tmp);
		order_count++;
	}
}

/* 乱数7つ以上 */
void	quicksort(t_bclist *a, t_bclist *b)
{
	int	x;	//軸要素
	int	n;
	int	min;
	t_bclist	*tmp;
	t_bclist	*tmptmp;

	//データの先頭の要素を軸要素とする
	x = a->next->num;

	//xより小さいものをaからbに送る
	tmp = a->next->next;
	while (tmp != a)
	{
		if (tmp->num < x)
		{
			tmptmp = tmp->next;
			pb(tmp, b);
			order_count++;	//カウント
			tmp = tmptmp;
		}
		else
			tmp = tmp->next;
	}

	//bを順番にaに戻す
	n = ft_bclstsize(b);
	while (n > 0)
	{
		min = b->next->num;
		tmp = b->next;
		while (tmp != b)
		{
			if (min > tmp->num)
				min = tmp->num;
			tmp = tmp->next;
		}
		tmp = b->next;
		while (tmp->num != min)
			tmp = tmp->next;
		pa(a, tmp);
		ra(a);
		order_count+=2;	//カウント
		n--;
	}

	//bから送られてきた要素は全て軸要素xよりも小さいので
	//前回の軸要素を一番下にする
	ra(a);

	//ソートが完了していなければもう一度
	if (check_sort(a))
		quicksort(a, b);
}

int	main(int argc, char **argv)
{
	t_bclist	*stack_a;
	t_bclist	*stack_b;

	/* 番兵ノードを作成 */
	stack_a = ft_bclstnew(0);
	stack_b = ft_bclstnew(0);
	/* スタックを初期化 */
	if (init_stack(argc, argv, stack_a))
		return (1);

	/* 引数2つ以下のソート */
	if (argc == 2)
		return (0);
	else if (argc == 3 && \
	ft_issmall(stack_a->next->num, stack_a->next->next->num))
		sa(stack_a);

	/* 引数3つ以下のソート */
	if (argc == 4)
		simple_sort(stack_a);

	/* 引数6つ以下のソート */
	if (argc <= 7)
		usually_sort(stack_a, stack_b);

	/* 引数7つ以上のソート */
	if (argc >= 8)
		quicksort(stack_a, stack_b);

	/* リストをプリント */
	bclst_print(stack_a, stack_b);

	/* ソートされているかチェック */
	if (!check_sort(stack_a))
		printf("\nSort        : OK\n");

	/* 命令回数をプリント */
	printf("order_count : %d\n\n", order_count);

	/* リークチェック */
	// system("leaks push_swap");
	return (0);
}


/* 要素生成コマンド */
//ARG=$(jot -r -s " " 100 -2147483648 2147483647); ./push_swap $ARG | ./checker $ARG
