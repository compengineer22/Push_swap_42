/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:48:51 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/18 17:49:26 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/*
** Move the node at position `index` to the top of stack_a.
** Chooses rotate or rev_rotate based on which is shorter.
*/
void	move_to_top(t_stack **stack_a, int index, int *tab)
{
	int	list_length;

	list_length = ft_lstlen(*stack_a);
	if (index > list_length / 2)
	{
		while (index < list_length)
		{
			rev_rotate(stack_a, NULL, 'a');
			index++;
			tab[8]++;
		}
	}
	else
	{
		while (index > 0)
		{
			rotate(stack_a, NULL, 'a');
			index--;
			tab[5]++;
		}
	}
}

/*
** Assign rank=0 to the `chunk_size` smallest unranked nodes in stack_a.
** Uses a selection approach: find the chunk_size-th smallest value,
** then mark all nodes with val <= that threshold.
** Nodes already pushed (rank==1) are ignored.
** This replaces the broken iterative ft_min approach.
*/
void	assign_ranks(t_stack **stack_a, int chunk_size)
{
	t_stack	*cur;
	int		*vals;
	int		total;
	int		i;
	int		j;
	int		tmp;
	int		threshold;

	/* Count unranked nodes */
	total = 0;
	cur = *stack_a;
	while (cur)
	{
		if (cur->rank != 1)
			total++;
		cur = cur->next;
	}
	if (total == 0)
		return ;
	if (chunk_size > total)
		chunk_size = total;

	/* Collect unranked values into temp array */
	vals = malloc(total * sizeof(int));
	if (!vals)
		return ;
	i = 0;
	cur = *stack_a;
	while (cur)
	{
		if (cur->rank != 1)
			vals[i++] = cur->val;
		cur = cur->next;
	}

	/* Partial selection sort to find the chunk_size-th smallest value */
	i = 0;
	while (i < chunk_size)
	{
		j = i + 1;
		while (j < total)
		{
			if (vals[j] < vals[i])
			{
				tmp = vals[i];
				vals[i] = vals[j];
				vals[j] = tmp;
			}
			j++;
		}
		i++;
	}
	threshold = vals[chunk_size - 1];
	free(vals);

	/* Mark nodes at or below threshold as rank=0 (to be pushed) */
	cur = *stack_a;
	while (cur)
	{
		if (cur->rank != 1 && cur->val <= threshold)
			cur->rank = 0;
		cur = cur->next;
	}
}

/*
** Push all nodes marked rank=0 from stack_a to stack_b.
** Scans from both ends towards the middle to minimise rotations.
** Stops when no more rank=0 nodes remain.
*/
void	move_chunks(t_stack **stack_a, t_stack **stack_b, int *tab)
{
	t_stack	*cur;
	int		index;
	int		list_len;

	assign_ranks(stack_a, radical(ft_lstlen(*stack_a) + ft_lstlen(*stack_b)));
	while (1)
	{
		/* Find nearest rank=0 node */
		cur = *stack_a;
		index = 0;
		list_len = ft_lstlen(*stack_a);
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

/*
** Returns the value of the maximum element in stack_a.
*/
int	ft_max(t_stack *stack_a)
{
	t_stack	*cur;
	int		cur_max;

	cur = stack_a;
	cur_max = cur->val;
	while (cur)
	{
		if (cur->val > cur_max)
			cur_max = cur->val;
		cur = cur->next;
	}
	return (cur_max);
}

/*
** Returns the minimum value among unranked (rank != 1) nodes.
** Marks that node rank=0. Used only by the old simple path — kept for
** compatibility but no longer called by move_chunks.
*/
int	ft_min(t_stack *stack_a)
{
	t_stack	*cur;
	t_stack	*min_node;

	cur = stack_a;
	min_node = NULL;
	while (cur)
	{
		if (cur->rank != 1)
		{
			if (!min_node || cur->val < min_node->val)
				min_node = cur;
		}
		cur = cur->next;
	}
	if (!min_node)
		return (0);
	min_node->rank = 0;
	return (min_node->val);
}

/*
** Returns the 0-based index of the maximum value node in stack_b.
*/
int	find_max_index(t_stack *stack_a)
{
	int		index;
	int		i;
	int		cur_max;
	t_stack	*cur;

	i = 0;
	index = 0;
	cur = stack_a;
	cur_max = stack_a->val;
	while (cur)
	{
		if (cur->val > cur_max)
		{
			index = i;
			cur_max = cur->val;
		}
		i++;
		cur = cur->next;
	}
	return (index);
}