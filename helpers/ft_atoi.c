/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:44:45 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/17 16:44:55 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

static int	ft_isspace(const char *str, int i)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\f' || str[i] == '\r'))
	{
		i++;
	}
	return (i);
}

int	is_zero(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

static void	check_sum(long sum, char **numbers, t_stack *s)
{
	int		i;
	t_stack	*cur;
	t_stack	*tmp;

	cur = s;
	i = ft_strlen_arr(numbers);
	if (sum > 2147483647 || sum < -2147483648)
	{
		if (numbers && *numbers)
		{
			while (i >= 0)
				free(numbers[i--]);
			free(numbers);
			while (cur)
			{
				tmp = cur->next;
				free(cur);
				cur = tmp;
			}
		}
		ft_end();
	}
}

int	ft_atoi(const char *nptr, char **numbers, t_stack *s)
{
	long	sum;
	int		i;
	int		sign;

	sign = 1;
	sum = 0;
	i = ft_isspace(nptr, 0);
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum = (sum * 10) + (nptr[i] - '0');
		check_sum(sign * sum, numbers, s);
		i++;
	}
	return (sign * sum);
}
