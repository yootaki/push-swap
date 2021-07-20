#include "mylibft.h"

/* eには未対応 */
double	ft_atof(char *s)
{
	double	sign;
	double	n;
	double	i;

	sign = 1;
	n = 0;
	i = 1;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		s++;
		sign = -1;
	}
	while (ft_isdigit(*s))
	{
		n = n * 10 + *s - '0';
		s++;
	}
	if (*s == '.')
	{
		while (ft_isdigit(*++s))
			n += (*s - '0') * (i *= 0.1);
	}
	return (n * sign);
}
