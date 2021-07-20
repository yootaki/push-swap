#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

//後で消す
#include <stdio.h>
int	order_count = 0;

/* 双方向循環リスト */
typedef struct s_bclist
{
	struct s_bclist	*prev;
	struct s_bclist	*next;
	int	num;
}t_bclist;

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
		printf(" %d   \n", a->num);
		a = a->next;
		a_size--;
	}
	while (b_size > a_size)
	{
		printf("   %d \n", b->num);
		b = b->next;
		b_size--;
	}
	while (a_size > 0)
	{
		printf(" %d %d \n", a->num, b->num);
		a = a->next;
		b = b->next;
		a_size--;
	}
	printf(" - - \n");
	printf(" a b \n");
}

/* 先頭を入れ替え */
void	sab(t_bclist *lst)
{
	int	tmp;

	//要素が一個またはからの場合何もしない
	if (lst->next->next == lst || lst->next == NULL)
		return ;
	tmp = lst->next->num;
	lst->next->num = lst->next->next->num;
	lst->next->next->num = tmp;
}
void	ss(t_bclist *a, t_bclist *b)
{
	sab(a);
	sab(b);
}

/* 先頭を一番後ろに */
void	rab(t_bclist *lst)
{
	t_bclist	*lst_last;
	t_bclist	*lst_top;
	t_bclist	*tmp;

	lst_last = lst->prev; //リストの最後
	lst_top = lst->next;  //リストの最初
	tmp = lst_top->next;  //リストの2個目
	lst_last->next = lst_top;
	lst_top->prev = lst_last;
	lst_top->next = lst;
	lst->prev = lst_top;
	lst->next = tmp;
	tmp->prev = lst;
}
void	rr(t_bclist *a, t_bclist *b)
{
	rab(a);
	rab(b);
}

/* 一番後ろを先頭に */
void	rrab(t_bclist *lst)
{
	t_bclist	*lst_last;
	t_bclist	*lst_top;
	t_bclist	*tmp;

	lst_last = lst->prev; //リストの最後
	lst_top = lst->next;  //リストの最初
	tmp = lst_last->prev; //リストの最後の一個前
	lst_top->prev = lst_last;
	lst_last->next = lst_top;
	lst_last->prev = lst;
	lst->next = lst_last;
	lst->prev = tmp;
	tmp->next = lst;
}
void	rrr(t_bclist *a, t_bclist *b)
{
	rrab(a);
	rrab(b);
}

/* bの先頭をaの先頭に */
void	pa(t_bclist *a, t_bclist *b)
{
	t_bclist	*a_top;
	t_bclist	*b_top;
	t_bclist	*tmp;

	if (b->next == NULL)
		return ;
	a_top = a->next;
	b_top = b->next;
	tmp = b_top->next;
	b->next = tmp;
	tmp->prev = b;
	a_top->prev = b_top;
	b_top->next = a_top;
	b_top->prev = a;
	a->next = b_top;
}

/* aの先頭をbの先頭に */
void	pb(t_bclist *a, t_bclist *b)
{
	t_bclist	*a_top;
	t_bclist	*b_top;
	t_bclist	*tmp;

	if (a->next == NULL)
		return ;
	a_top = a->next;
	b_top = b->next;
	tmp = a_top->next;
	a->next = tmp;
	tmp->prev = a;
	b_top->prev = a_top;
	a_top->next = b_top;
	a_top->prev = b;
	b->next = a_top;
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
	if (lst1 < last && lst1 > lst2)
	{
		sab(a);
		order_count++;
	}
	else if (lst1 > last && lst1 > lst2 && lst2 > last)
	{
		sab(a);
		rrab(a);
		order_count += 2;
	}
	else if (lst1 > last && lst1 > lst2 && lst2 < last)
	{
		rab(a);
		order_count++;
	}
	else if (lst1 < last && lst1 < lst2)
	{
		sab(a);
		rab(a);
		order_count += 2;
	}
	else if (lst1 > last && lst1 < lst2)
	{
		rrab(a);
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
// void	usually_sort(t_bclist *a, t_bclist *b)
// {
// 	//aの上位二つをbに移動
// 	pb(a, b);
// 	pb(a, b);
// 	order_count += 2;
// 	//aをソート
// 	simple_sort(a);

// 	//bからaに移動 & 数値の代償を確認
// 	pa(a, b);
// 	if (a->next->num > a->next->next->num)
// 	{
// 		rab(a);
// 		order_count++;
// 	}
// 	pa(a, b);
// 	if (a->next->num > a->next->next->num)
// 	{
// 		rab(a);
// 		order_count++;
// 	}
// 	order_count += 2;

// 	if (check_sort(a))
// 		usually_sort(a, b);
// }

void	usually_sort(t_bclist *a, t_bclist *b)
{
	(void)b;

	int			n;
	int			min;
	t_bclist	*tmp;

	//aの最小値を、aが3個以下になるまでbに送る
	n = ft_bclstsize(a);
	while (n > 3)
	{
		min = a->next->num;
		tmp = a->next;
		while (tmp != a)
		{
			if (min < tmp->num)
				min = tmp->num;
			tmp = tmp->next;
		}
		tmp = a->next;
		while (tmp->num != min)
			tmp = tmp->next;
		pb(tmp, b);
		order_count++;
		n--;
	}

	//aをソート
	// simple_sort(a);

	//bからaに移動 & 数値の代償を確認
	// while (b->next != b)
	// {
	// 	pa(a, b);
	// 	order_count += 2;
	// }

	// if (check_sort(a))
	// 	usually_sort(a, b);
}

int	main(int argc, char **argv)
{
	int	i;
	t_bclist	*stack_a;
	t_bclist	*stack_b;
	t_bclist	*tmp;

	stack_a = ft_bclstnew(0);
	stack_b = ft_bclstnew(0);
	/* コマンドライン引数で受け取った数字をリストに格納 */
	i = 0;
	while (++i < argc)
	{
		tmp = ft_bclstnew(ft_atoi(argv[i]));
		ft_bclstadd_back(stack_a, tmp);
	}

	/* コマンド */
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
	/* ------ */

	/* 引数3つ以下のソート */
	// simple_sort(stack_a);

	/* 引数6つ以下のソート */
	usually_sort(stack_a, stack_b);

	/* リストをプリント */
	bclst_print(stack_a, stack_b);

	/* 命令回数をプリント */
	printf("order_count : %d\n", order_count);

	/* リークチェック */
	// system("leaks a.out");
	return (0);
}
