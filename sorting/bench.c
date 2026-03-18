/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:11:17 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/17 17:11:27 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*helper(long n, char *str, int sign, int i)
{
	if (sign == -1)
	{
		str[0] = '-';
		helper(n, str, 1, i);
	}
	else
	{
		if (n > 9)
		{
			helper(n / 10, str, sign, i - 1);
		}
		str[i - 1] = n % 10 + '0';
	}
	str[i] = '\0';
	return (str);
}

static int	nlen(long l)
{
	int	i;

	i = 0;
	while (l > 0)
	{
		l /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	long	l;
	int		i;

	i = 0;
	num = (long)n;
	if (num < 0)
		num *= -1;
	l = num;
	if (l == 0)
		i++;
	i += nlen(l);
	if (n < 0)
	{
		str = malloc(i + 2);
		if (!str)
			return (NULL);
		return (helper(num, str, -1, i + 1));
	}
	else
		str = malloc(i + 2);
	if (!str)
		return (NULL);
	return (helper(num, str, l, i));
}

void	print_disorder(double disorder, char *dis)
{
	if (disorder == 1)
		ft_printf(2, "disorder: 100%%\n");
	else if (disorder == 0)
		ft_printf(2, "disorder: 0.00%%\n");
	else if (dis[0] == '-')
		ft_printf(2, "disorder: 0.00%%\n");
	else
		ft_printf(2, "disorder: %c%c.%c%c%%\n", dis[0], dis[1], dis[2], dis[3]);
}

void	print_bench(double d, char *flag, int *t)
{
	char	*dis;

	dis = ft_itoa((int)(d * 10000));
	ft_printf(2, "[bench] ");
	print_disorder(d, dis);
	if (!ft_strcmp(flag, "--adaptive") && d >= 0.2 && d < 0.5)
		ft_printf(2, "[bench] strategy: Adaptive / O(n√n)\n");
	else if (!ft_strcmp(flag, "--adaptive") && (d < 0.2))
		ft_printf(2, "[bench] strategy: Adaptive / O(n²)\n");
	else if (!ft_strcmp(flag, "--adaptive"))
		ft_printf(2, "[bench] strategy: Adaptive / O(nlog(n))\n");
	else if (!ft_strcmp(flag, "--simple"))
		ft_printf(2, "[bench] strategy: Simple / O(n²)\n");
	else if (!ft_strcmp(flag, "--medium"))
		ft_printf(2, "[bench] strategy: Medium / O(n√n)\n");
	else if (!ft_strcmp(flag, "--complex"))
		ft_printf(2, "[bench] strategy: Complex / O(nlog(n))\n");
	ft_printf(2, "[bench] ");
	ft_printf(2, "total_ops: %d\n", t[3] + t[4] + t[5] + t[6] + t[8] + t[9]
		+ t[0] + t[1] + t[2] + t[7] + t[10]);
	ft_printf(2, "[bench] ");
	ft_printf(2, "sa: %d sb: %d ss: %d pa: %d", t[0], t[1], t[2], t[3]);
	ft_printf(2, " pb: %d\n[bench] ra: %d rb: %d", t[4], t[5], t[6]);
	ft_printf(2, " rr: %d rra: %d rrb: %d rrr: %d\n", t[7], t[8], t[9], t[10]);
	free(dis);
}
