/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:48:35 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/18 17:49:29 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	extract_maximum(t_stack **stack_a, t_stack **stack_b, int *tab)
{
	int	i;
	int	len;

	len = ft_lstlen(*stack_b);
	i = find_max_index(*stack_b);
	if (i <= len / 2)
	{
		while (find_max_index(*stack_b) != 0)
		{
			rotate(stack_a, stack_b, 'b');
			tab[6]++;
		}
	}
	else
	{
		while (find_max_index(*stack_b) != 0)
		{
			rev_rotate(stack_a, stack_b, 'b');
			tab[9]++;
		}
	}
	(*stack_b)->rank = 1;
	pa(stack_a, stack_b);
	tab[3]++;
}

static void	push_chunk(t_stack **stack_a, t_stack **stack_b, int *tab)
{
	t_stack	*cur;
	int		index;

	cur = *stack_a;
	index = 0;
	while (1)
	{
		cur = *stack_a;
		index = 0;
		while (cur && cur->rank != 0)
		{
			cur = cur->next;
			index++;
		}
		if (!cur)
			break ;
		move_to_top(stack_a, index, tab);
		pb(stack_a, stack_b);
		tab[4]++;
	}
}

void	bucker_sort(t_stack **stack_a, t_stack **stack_b, int length, int *tab)
{
	int	chunk;
	int	i;

	if (ft_lstlen(*stack_a) <= 1 || compute_disorder(*stack_a) == 0)
		return ;
	chunk = radical(length);
	if (chunk < 1)
		chunk = 1;
	while (*stack_a)
	{
		assign_ranks(stack_a, chunk);
		push_chunk(stack_a, stack_b, tab);
	}
	i = 0;
	while (i++ < length)
		extract_maximum(stack_a, stack_b, tab);
}