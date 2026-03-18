/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:08:43 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/17 17:08:52 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*cur;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	temp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	cur = (*stack_a);
	while (cur->next)
		cur = cur->next;
	cur->next = temp;
	temp->next = NULL;
	return (1);
}

int	rb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*cur;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return (0);
	temp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	cur = (*stack_b);
	while (cur->next)
		cur = cur->next;
	cur->next = temp;
	temp->next = NULL;
	return (1);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !stack_a || !*stack_a)
		return (0);
	if ((*stack_b)->next && (*stack_a)->next)
	{
		ra(stack_a);
		rb(stack_b);
		return (1);
	}
	return (0);
}

void	rotate(t_stack **stack_a, t_stack **stack_b, char choice)
{
	if (choice == 'a' && ra(stack_a))
		write(1, "ra\n", 3);
	else if (choice == 'b' && rb(stack_b))
		write(1, "rb\n", 3);
	else if (choice == 's' && rr(stack_a, stack_b))
		write(1, "rr\n", 3);
}
