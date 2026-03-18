/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_less.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:01:33 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/18 17:49:36 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_2(t_stack **stack_a, int *tab)
{
	if ((*stack_a)->val > (*stack_a)->next->val)
	{
		swap(stack_a, NULL, 'a');
		tab[0]++;
	}
}

void	handle_3(t_stack **a, int *tab)
{
	if ((*a)->val < (*a)->next->val)
	{
		if ((*a)->next->val < (*a)->next->next->val)
			return ;
		else
		{
			swap(a, NULL, 'a');
			tab[0]++;
			rotate(a, NULL, 'a');
			tab[5]++;
		}
	}
	else if (tail(*a)->val > (*a)->val && (*a)->val > (*a)->next->val)
	{
		swap(a, NULL, 'a');
		tab[0]++;
	}
	else if (tail(*a)->val < (*a)->val && (*a)->val < (*a)->next->val)
	{
		rev_rotate(a, NULL, 'a');
		tab[8]++;
	}
}

void	handle_3_2(t_stack **a, int *tab)
{
	if ((*a)->val > tail(*a)->val && tail(*a)->val > (*a)->next->val)
	{
		rotate(a, NULL, 'a');
		tab[5]++;
	}
	else if ((*a)->val > (*a)->next->val && (*a)->next->val > tail(*a)->val)
	{
		swap(a, NULL, 'a');
		rev_rotate(a, NULL, 'a');
		tab[0]++;
		tab[8]++;
	}
}

/*
** Sort 4 elements:
** Push the minimum to b, sort the remaining 3, then pa.
*/
static void	handle_4(t_stack **a, t_stack **b, int *tab)
{
	int	min_idx;

	min_idx = find_min_index(*a);
	move_to_top(a, min_idx, tab);
	pb(a, b);
	tab[4]++;
	handle_3(a, tab);
	handle_3_2(a, tab);
	pa(a, b);
	tab[3]++;
}

/*
** Sort 5 elements:
** Push the two smallest to b, sort remaining 3 in a, then pa twice.
** pull back in order: find max of b first so larger one goes to a first.
*/
static void	handle_5(t_stack **a, t_stack **b, int *tab)
{
	int	min_idx;
	int	i;

	i = 0;
	while (i < 2)
	{
		min_idx = find_min_index(*a);
		move_to_top(a, min_idx, tab);
		pb(a, b);
		tab[4]++;
		i++;
	}
	handle_3(a, tab);
	handle_3_2(a, tab);
	/* b has 2 elements: bring the larger one to top before pa-ing both */
	if ((*b)->val < (*b)->next->val)
	{
		rotate(a, b, 'b');
		tab[6]++;
	}
	pa(a, b);
	tab[3]++;
	pa(a, b);
	tab[3]++;
}

void	handler(t_stack **a, int *tab)
{
	t_stack	*b;

	b = NULL;
	if (ft_lstlen(*a) == 5)
		handle_5(a, &b, tab);
	else if (ft_lstlen(*a) == 4)
		handle_4(a, &b, tab);
	else if (ft_lstlen(*a) == 3)
	{
		handle_3(a, tab);
		handle_3_2(a, tab);
	}
	else if (ft_lstlen(*a) == 2)
		handle_2(a, tab);
}