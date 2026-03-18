/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:10:14 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/17 17:10:21 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_log(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n /= 2;
	}
	return ((i - 1));
}

int	radical(int length)
{
	int	i;

	i = 1;
	while (i <= length / i)
		i++;
	return (i - 1);
}

int	ft_pow(int power)
{
	int	n;

	n = 1;
	while (power)
	{
		n *= 2;
		power--;
	}
	return (n);
}

void	advance(t_stack **cur, t_stack **cur2, int *index, int *index2)
{
	(*index)++;
	(*index2)--;
	*cur = (*cur)->next;
	*cur2 = prev(*cur, *cur2);
}

void	delete(char **numbers)
{
	if (ft_strlen_arr(numbers) == 0)
	{
		free(numbers);
		ft_end();
	}
}
