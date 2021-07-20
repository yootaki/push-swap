#include "mylibft.h"

/* aとbを比較して大きい方の数字を返す */
int	ft_islarge(int a, int b)
{
	if (a > b)
		return (a);
	else if (a < b)
		return (b);
	else
		return (a);
}
