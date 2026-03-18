/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:27:19 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/19 00:27:28 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	find_min_index(t_stack *stack_a)
{
	int		index;
	int		i;
	int		cur_min;
	t_stack	*cur;

	i = 0;
	index = 0;
	cur = stack_a;
	cur_min = stack_a->val;
	while (cur)
	{
		if (cur->val < cur_min)
		{
			index = i;
			cur_min = cur->val;
		}
		i++;
		cur = cur->next;
	}
	return (index);
}

/*
** Check if stack_a is sorted in ascending order.
** Returns 1 if sorted, 0 otherwise.
** Safer than comparing compute_disorder() == 0 with floats.
*/
static int	is_sorted(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->val > stack_a->next->val)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	extract_minimum(t_stack **stack_a, t_stack **stack_b, int *tab)
{
	int	list_length;
	int	i;

	list_length = ft_lstlen(*stack_a);
	i = find_min_index(*stack_a);
	if (i > list_length / 2)
	{
		while (i < list_length)
		{
			rev_rotate(stack_a, stack_b, 'a');
			tab[8]++;
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			rotate(stack_a, stack_b, 'a');
			tab[5]++;
			i--;
		}
	}
	pb(stack_a, stack_b);
	tab[4]++;
}

void	simple(t_stack **stack_a, t_stack **stack_b, int *tab)
{
	if (ft_lstlen(*stack_a) <= 1 || is_sorted(*stack_a))
		return ;
	while (*stack_a)
		extract_minimum(stack_a, stack_b, tab);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		tab[3]++;
	}
}