#include "../includes/libft/libft.h"
#include "../includes/mylibft/mylibft.h"
#include "../includes/get_next_line/get_next_line.h"
#include "../includes/push_swap.h"

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
		sa(a, PS);
	else if (lst1 > lst2 && lst2 > last && last < lst1)
	{
		sa(a, PS);
		rra(a, PS);
	}
	else if (lst1 > last && lst1 > lst2 && lst2 < last)
		ra(a, PS);
	else if (lst1 < last && lst1 < lst2 && lst2 > last)
	{
		sa(a, PS);
		ra(a, PS);
	}
	else if (lst1 < lst2 && lst2 > last && lst1 > last)
		rra(a, PS);
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
			if (n <= a_size / 2)
				ra(tmp, PS);
			else
				rra(tmp, PS);
		}
		pb(tmp->next, b, PS);
		a_size--;
	}
	simple_sort(a);
	while (b->next != b)
	{
		tmp = b->next;
		pa(a, tmp, PS);
	}
}

/* 基数ソート */
void	my_radix_sort(t_bclist *a, t_bclist *b, int *nums)
{
	t_bclist	*tmp_a;
	t_bclist	*tmp_b;
	int			i;
	int			j;
	int			n;

	/* スタックaを単純化 */
	tmp_a = a->next;						//スタックaの最初の数字
	n = ft_bclstsize(a);
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			if (tmp_a->num == nums[j])	//一致したらインデックス番号を入れる
			{
				tmp_a->num = j;
				break ;
			}
		}
		tmp_a = tmp_a->next;
	}

	/* ビット演算でソート */
	int	max_num;
	int	max_bit;
	max_num = n - 1;
	max_bit = 0;
	while (max_num >> max_bit != 0)		//最大bit数を計算
		max_bit++;
	i = -1;
	while (++i < max_bit)
	{
		n = ft_bclstsize(a);
		j = -1;
		while (++j < n)
		{
			tmp_a = a->next;
			if (((tmp_a->num >> i) & 1) == 1)
				ra(a, PS);
			else
				pb(tmp_a, b, PS);
		}
		tmp_b = b->next;
		while (tmp_b != b)
		{
			tmp_b = tmp_b->next;
			// if (((tmp_b->num >> (i + 1)) & 1) == 0 && i + 1 < max_bit && tmp_b->next == b)
			// 	break ;
			pa(a, tmp_b->prev, PS);
		}
	}
}

//引数なし
//引数多すぎ
//数字じゃない
//重複
//ソートされている...これはOKを出して終了
int	args_check(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (argc > 10000)	/* 引数が多すぎたらタイムアウトするからエラーとする */
		return (1);
}

int	main(int argc, char **argv)
{
	t_bclist	*stack_a;
	t_bclist	*stack_b;
	int			nums[argc - 1];

	stack_a = ft_bclstnew(0);
	stack_b = ft_bclstnew(0);	//こいつらを最初にやらないとダブルfreeなる
	/* 引数のチェック */
	if (args_check(argc, argv))
		ps_error_print(stack_a, stack_b);

	if (init_stack(argc, argv, stack_a, nums))
		ps_error_print(stack_a, stack_b);

	/* 引数2つ以下のソート */
	if (argc == 2)
		return (0);
	else if (argc == 3 && \
	ft_issmall(stack_a->next->num, stack_a->next->next->num))
		sa(stack_a, PS);

	/* 引数3つ以下のソート */
	if (argc == 4)
		simple_sort(stack_a);

	/* 引数5つ以下のソート */
	if (argc <= 6)
		usually_sort(stack_a, stack_b);

	/* 引数7つ以上のソート */
	if (argc >= 7)
		my_radix_sort(stack_a, stack_b, nums);
	return (0);
}
