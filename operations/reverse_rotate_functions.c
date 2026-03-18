/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:09:07 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/17 17:48:57 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack **stack_a)
{
	t_stack	*cur;
	t_stack	*temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	cur = *stack_a;
	while (cur->next->next)
		cur = cur->next;
	temp = cur->next;
	cur->next = NULL;
	temp->next = *stack_a;
	*stack_a = temp;
	return (1);
}

int	rrb(t_stack **stack_b)
{
	t_stack	*cur;
	t_stack	*temp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	cur = *stack_b;
	while (cur->next->next)
		cur = cur->next;
	temp = cur->next;
	cur->next = NULL;
	temp->next = *stack_b;
	*stack_b = temp;
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !stack_a || !*stack_a)
		return (0);
	if ((*stack_b)->next && (*stack_a)->next)
	{
		rra(stack_a);
		rrb(stack_b);
		return (1);
	}
	return (0);
}

void	rev_rotate(t_stack **stack_a, t_stack **stack_b, char choice)
{
	if (choice == 'a' && rra(stack_a))
		write(1, "rra\n", 4);
	else if (choice == 'b' && rrb(stack_b))
		write(1, "rrb\n", 4);
	else if (choice == 's' && rrr(stack_a, stack_b))
		write(1, "rrr\n", 4);
}
