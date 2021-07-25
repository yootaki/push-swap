#include "../includes/libft/libft.h"
#include "../includes/mylibft/mylibft.h"
#include "../includes/push_swap.h"

/* 先頭を入れ替え */
int	sa(t_bclist *a)
{
	int	tmp;

	write(1, "sa\n", 3);
	//要素が一個またはからの場合何もしない
	if (a->next->next == a || a->next == NULL)
		return (1);
	tmp = a->next->num;
	a->next->num = a->next->next->num;
	a->next->next->num = tmp;
	return (0);
}
int	sb(t_bclist *b)
{
	int	tmp;

	write(1, "sb\n", 3);
	//要素が一個またはからの場合何もしない
	if (b->next->next == b || b->next == NULL)
		return (1);
	tmp = b->next->num;
	b->next->num = b->next->next->num;
	b->next->next->num = tmp;
	return (0);
}
int	ss(t_bclist *a, t_bclist *b)
{
	write(1, "ss\n", 3);
	if (sa(a) || sb(b))
		return (1);
	return (0);
}

/* 先頭を一番後ろに */
int	ra(t_bclist *a)
{
	t_bclist	*a_last;
	t_bclist	*a_top;
	t_bclist	*tmp;

	write(1, "ra\n", 3);
	if (a == NULL)
		return (1);
	if (a->next == a || a->next->next == a)
		return (0);
	a_last = a->prev; //リストの最後
	a_top = a->next;  //リストの最初
	tmp = a_top->next;  //リストの2個目
	a_last->next = a_top;
	a_top->prev = a_last;
	a_top->next = a;
	a->prev = a_top;
	a->next = tmp;
	tmp->prev = a;
	return (0);
}
int	rb(t_bclist *b)
{
	t_bclist	*b_last;
	t_bclist	*b_top;
	t_bclist	*tmp;

	write(1, "rb\n", 3);
	if (b == NULL)
		return (1);
	if (b->next == b || b->next->next == b) //要素が1個の時は何もしない
		return (0);
	b_last = b->prev; //リストの最後
	b_top = b->next;  //リストの最初
	tmp = b_top->next;  //リストの2個目
	b_last->next = b_top;
	b_top->prev = b_last;
	b_top->next = b;
	b->prev = b_top;
	b->next = tmp;
	tmp->prev = b;
	return (0);
}
int	rr(t_bclist *a, t_bclist *b)
{
	write(1, "rr\n", 3);
	if(ra(a) || rb(b))
		return (1);
	return (0);
}

/* 一番後ろを先頭に */
int	rra(t_bclist *a)
{
	t_bclist	*a_last;
	t_bclist	*a_top;
	t_bclist	*tmp;

	write(1, "rra\n", 4);
	if (a == NULL)
		return (1);
	if (a->next == a || a->next->next == a)
		return (0);
	a_last = a->prev; //リストの最後
	a_top = a->next;  //リストの最初
	tmp = a_last->prev; //リストの最後の一個前
	a_top->prev = a_last;
	a_last->next = a_top;
	a_last->prev = a;
	a->next = a_last;
	a->prev = tmp;
	tmp->next = a;
	return (0);
}
int	rrb(t_bclist *b)
{
	t_bclist	*b_last;
	t_bclist	*b_top;
	t_bclist	*tmp;

	write(1, "rrb\n", 4);
	if (b == NULL)
		return (1);
	if (b->next == b || b->next->next == b)
		return (0);
	b_last = b->prev; //リストの最後
	b_top = b->next;  //リストの最初
	tmp = b_last->prev; //リストの最後の一個前
	b_top->prev = b_last;
	b_last->next = b_top;
	b_last->prev = b;
	b->next = b_last;
	b->prev = tmp;
	tmp->next = b;
	return (0);
}
int	rrr(t_bclist *a, t_bclist *b)
{
	write(1, "rrr\n", 4);
	if (rra(a) || rrb(b))
		return (1);
	return (0);
}

/* bの先頭をaの先頭に */
/* bはダミーの次(つまりスタックの一番上渡す) */
int	pa(t_bclist *a, t_bclist *b)
{
	t_bclist	*a_top;
	t_bclist	*b_top;
	t_bclist	*tmp;

	write(1, "pa\n", 3);
	if (a == NULL || b == NULL || b->next == b)
		return (1);
	a_top = a->next;
	b_top = b;
	tmp = b_top->next; //上から2ばんめ
	b->prev->next = tmp;
	tmp->prev = b->prev;
	a_top->prev = b_top;
	b_top->next = a_top;
	b_top->prev = a;
	a->next = b_top;
	return (0);
}

/* aの先頭をbの先頭に */
/* aはダミーの次(つまりスタックの一番上渡す) */
int	pb(t_bclist *a, t_bclist *b)
{
	t_bclist	*a_top;
	t_bclist	*b_top;
	t_bclist	*tmp;

	write(1, "pb\n", 3);
	if (a == NULL || b == NULL || a->next == a)
		return (1);
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
	return (0);
}
