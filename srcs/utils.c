#include "../includes/get_next_line/get_next_line.h"
#include "../includes/mylibft/mylibft.h"
#include "../includes/push_swap.h"

void	ps_error_print(t_bclist *a, t_bclist *b, int *nums)
{
	lst_free(a);
	lst_free(b);
	free(nums);
	write(2, "Error\n", 6);
	exit(1);
}

void	ch_error_print(t_bclist *a, t_bclist *b, int *nums, char *cmd)
{
	lst_free(a);
	lst_free(b);
	free(nums);
	free(cmd);
	write(2, "Error\n", 6);
	exit(1);
}
