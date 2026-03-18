/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:56:47 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/18 17:46:49 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:28:20 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/17 17:28:33 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Coordinate-compress stack_a values into integer ranks [0, length-1].
** This lets us use bit-level chunk splitting cleanly.
** After normalise(), node->rank holds the element's sorted position.
*/
static void	normalise(t_stack **a, int length)
{
	t_stack	*cur;
	t_stack	*inner;
	int		rank;

	cur = *a;
	while (cur)
	{
		rank = 0;
		inner = *a;
		while (inner)
		{
			if (inner->val < cur->val)
				rank++;
			inner = inner->next;
		}
		cur->rank = rank;
		cur = cur->next;
	}
	(void)length;
}

/*
** Push all nodes whose rank has bit `bit` cleared (0) to stack_b.
** This is one pass of the radix sort.
*/
static void	push_bit_zero(t_stack **a, t_stack **b, int bit, int *tab)
{
	int	size;
	int	i;

	size = ft_lstlen(*a);
	i = 0;
	while (i < size)
	{
		if (((*a)->rank >> bit) & 1)
		{
			rotate(a, NULL, 'a');
			tab[5]++;
		}
		else
		{
			pb(a, b);
			tab[4]++;
		}
		i++;
	}
}

/*
** Push all nodes from stack_b back to stack_a.
*/
static void	push_all_back(t_stack **a, t_stack **b, int *tab)
{
	while (*b)
	{
		pa(a, b);
		tab[3]++;
	}
}

/*
** O(n log n) LSD radix sort.
**
** How it works:
**   1. Normalise all values to ranks 0..n-1 (coordinate compression).
**   2. For each bit position (LSB to MSB):
**      - Push nodes with that bit = 0 to stack_b.
**      - Rotate nodes with that bit = 1 to the back of stack_a.
**      - Push everything from stack_b back to stack_a.
**   After ft_log(n) passes the stack is sorted.
**
** Why this is better than the old burcker approach:
**   - Guaranteed O(n log n) operations with no edge cases for
**     non-power-of-2 sizes.
**   - No fragile rank=0 marking or missed chunks.
**   - Every element is touched exactly twice per bit pass.
*/
void	burcker_sort(t_stack **a, t_stack **b, int length, int *tab)
{
	int	bits;
	int	i;

	if (ft_lstlen(*a) <= 1 || compute_disorder(*a) == 0)
		return ;

	normalise(a, length);

	/* Number of bit passes needed = ceil(log2(length)) */
	bits = 0;
	while ((1 << bits) < length)
		bits++;
	if (bits == 0)
		bits = 1;

	i = 0;
	while (i < bits)
	{
		push_bit_zero(a, b, i, tab);
		push_all_back(a, b, tab);
		i++;
	}
}

/*
** These two functions are kept for ABI compatibility (declared in push_swap.h)
** but now simply delegate to burcker_sort which handles all cases uniformly.
*/
void	perfect_burcker(t_stack **a, t_stack **b, int length, int *tab)
{
	burcker_sort(a, b, length, tab);
}

void	burcker_no_log(t_stack **a, t_stack **b, int length, int *tab)
{
	burcker_sort(a, b, length, tab);
}

void	burcker_chunks(t_stack **a, t_stack **b, int chunk_size, int *tab)
{
	(void)chunk_size;
	burcker_sort(a, b, ft_lstlen(*a) + ft_lstlen(*b), tab);
}