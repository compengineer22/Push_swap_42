/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:07:30 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/17 17:07:41 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack **stack_a)
{
	t_stack	*temp;

	if (!stack_a || !*stack_a)
		return (0);
	if (ft_lstlen(*stack_a) <= 1)
		return (0);
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	return (1);
}

int	sb(t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_b || !*stack_b)
		return (0);
	if (ft_lstlen(*stack_b) <= 1)
		return (0);
	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
	return (1);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !stack_a || !*stack_a)
		return (0);
	if (ft_lstlen(*stack_b) > 1 && ft_lstlen(*stack_a) > 1)
	{
		sa(stack_a);
		sb(stack_b);
		return (1);
	}
	return (0);
}

void	swap(t_stack **stack_a, t_stack **stack_b, char choice)
{
	if (choice == 'a' && sa(stack_a))
		write(1, "sa\n", 3);
	else if (choice == 'b' && sb(stack_b))
		write(1, "sb\n", 3);
	else if (choice == 's' && ss(stack_a, stack_b))
		write(1, "ss\n", 3);
}
