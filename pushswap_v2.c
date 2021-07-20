#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./mylibft/mylibft.h"

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
/* bはダミーの次(つまりスタックの一番上渡す) */
void	pa(t_bclist *a, t_bclist *b)
{
	t_bclist	*a_top;
	t_bclist	*b_top;
	t_bclist	*tmp;

	if (b == NULL)
		return ;
	a_top = a->next;
	b_top = b;
	tmp = b_top->next; //上から2ばんめ
	b->prev->next = tmp;
	tmp->prev = b->prev;
	a_top->prev = b_top;
	b_top->next = a_top;
	b_top->prev = a;
	a->next = b_top;
}

/* aの先頭をbの先頭に */
/* aはダミーの次(つまりスタックの一番上渡す) */
void	pb(t_bclist *a, t_bclist *b)
{
	t_bclist	*a_top;
	t_bclist	*b_top;
	t_bclist	*tmp;

	if (a == NULL)
		return ;
	a_top = a;
	b_top = b->next;
	tmp = a_top->next; //上から2ばんめ
	//aをつなぎわせる
	a->prev->next = tmp;
	tmp->prev = a->prev;
	//aをbに送る
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
	if (lst1 > lst2 && lst2 < last && last > lst1)
	{
		sab(a);
		order_count++;
	}
	else if (lst1 > lst2 && lst2 > last && last < lst1)
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
	else if (lst1 < last && lst1 < lst2 && lst2 > last)
	{
		sab(a);
		rab(a);
		order_count += 2;
	}
	else if (lst1 < lst2 && lst2 > last && lst1 > last)
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
			if (min > tmp->num)
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
	simple_sort(a);

	//bからaに移動 & 数値の大小を確認
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
	//1.軸要素決定
	//いろいろ決め方があるが今回は一番下で行う
	// ○データの先頭の要素を軸要素とする
	// ×ランダムに1つ選ぶ
	// ×ランダムに3つ選んで、その中央値を取る
	// ×左から見て最初に得られた2つの異なる値の大きいほうを取る
	//2.小さいものをbに送る
	//3.小さい順にaに戻し、aの一番下につけていく
	//4.bが空になったらまた手順1から繰り返す

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
		rab(a);
		order_count+=2;	//カウント
		n--;
	}

	//bから送られてきた要素は全て軸要素xよりも小さいので
	//前回の軸要素を一番下にする
	rab(a);

	//ソートが完了していなければもう一度
	if (check_sort(a))
		quicksort(a, b);
}

int	main(int argc, char **argv)
{
	int	i;
	t_bclist	*stack_a;
	t_bclist	*stack_b;
	t_bclist	*tmp;

	/* 番兵ノードを作成 */
	stack_a = ft_bclstnew(0);
	stack_b = ft_bclstnew(0);
	/* コマンドライン引数で受け取った数字をリストに格納 */
	i = 0;
	while (++i < argc)
	{
		tmp = ft_bclstnew(ft_atoi(argv[i]));
		ft_bclstadd_back(stack_a, tmp);
	}

	/* 引数2つ以下のソート */
	if (argc == 2)
		return (0);
	else if (argc == 3 && \
	ft_issmall(stack_a->next->num, stack_a->next->next->num))
		sab(stack_a);

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
		printf("Sort OK!!!");

	/* 命令回数をプリント */
	printf("order_count : %d\n", order_count);

	/* リークチェック */
	// system("leaks a.out");
	return (0);
}


/* 要素生成コマンド */
//ARG=$(jot -r -s " " 100 -2147483648 2147483647); ./push_swap $ARG | ./checker $ARG
