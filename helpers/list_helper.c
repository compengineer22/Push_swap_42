/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:04:09 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/19 00:04:28 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstlen(t_stack *s)
{
	t_stack	*cur;
	int		i;

	i = 0;
	cur = s;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

int	check_dup_sep(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (!ft_strcmp(numbers[i], numbers[j]))
			{
				ft_end();
			}
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	*prev(t_stack	*a,	t_stack	*b)
{
	if (!a || !b)
		return (NULL);
	while (a && a->next != b)
		a = a->next;
	if (a == b)
		return (NULL);
	return (a);
}

t_stack	*tail(t_stack	*a)
{
	t_stack	*b;

	b = a;
	while (b->next)
		b = b->next;
	return (b);
}

t_stack	*initialize(t_stack *a, t_stack **cur, int *index, int *index2)
{
	*cur = a;
	*index = 0;
	*index2 = ft_lstlen(a) - 1;
	return (tail(a));
}