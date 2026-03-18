/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:27:38 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/19 00:27:44 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->val > a->next->val)
			return (0);
		a = a->next;
	}
	return (1);
}

void	run_adaptive(t_stack **sa, t_stack **sb, int *tab)
{
	double	disorder;

	if (is_sorted(*sa))
		return ;
	disorder = compute_disorder(*sa);
	handler(sa, tab);
	if (is_sorted(*sa))
		return ;
	if (disorder < 0.2)
		simple(sa, sb, tab);
	else if (disorder >= 0.2 && disorder < 0.5)
		bucker_sort(sa, sb, ft_lstlen(*sa), tab);
	else
		burcker_sort(sa, sb, ft_lstlen(*sa), tab);
}

void	run_one_flag(char *argv[], t_stack **sa, t_stack **sb, int *tab)
{
	double	disorder;

	disorder = compute_disorder(*sa);
	handler(sa, tab);
	if (is_sorted(*sa))
	{
		if (!ft_strcmp(argv[1], "--bench"))
			print_bench(disorder, "--adaptive", tab);
		return ;
	}
	if (!ft_strcmp(argv[1], "--simple"))
		simple(sa, sb, tab);
	else if (!ft_strcmp(argv[1], "--medium"))
		bucker_sort(sa, sb, ft_lstlen(*sa), tab);
	else if (!ft_strcmp(argv[1], "--complex"))
		burcker_sort(sa, sb, ft_lstlen(*sa), tab);
	if (!ft_strcmp(argv[1], "--bench") || !ft_strcmp(argv[1], "--adaptive"))
	{
		run_adaptive(sa, sb, tab);
		if (!ft_strcmp(argv[1], "--bench"))
			print_bench(disorder, "--adaptive", tab);
	}
}

void	run_two_flags(char *argv[], t_stack **a, t_stack **b, int *tab)
{
	double	disorder;

	disorder = compute_disorder(*a);
	handler(a, tab);
	if (is_sorted(*a))
	{
		if (!ft_strcmp(argv[1], "--bench"))
			print_bench(disorder, argv[2], tab);
		else
			print_bench(disorder, argv[1], tab);
		return ;
	}
	if (!ft_strcmp(argv[1], "--simple") || !ft_strcmp(argv[2], "--simple"))
		simple(a, b, tab);
	else if (!ft_strcmp(argv[1], "--medium") || !ft_strcmp(argv[2], "--medium"))
		bucker_sort(a, b, ft_lstlen(*a), tab);
	else if (!ft_strcmp(argv[1], "--complex")
		|| !ft_strcmp(argv[2], "--complex"))
		burcker_sort(a, b, ft_lstlen(*a), tab);
	else
		run_adaptive(a, b, tab);
	if (!ft_strcmp(argv[1], "--bench"))
		print_bench(disorder, argv[2], tab);
	else
		print_bench(disorder, argv[1], tab);
}

void	set_rank(t_stack **stack_a)
{
	t_stack	*cur;

	cur = *stack_a;
	while (cur)
	{
		cur->rank = -1;
		cur = cur->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		n;
	int		*tab;

	stack_b = NULL;
	stack_a = NULL;
	if (argc == 1)
		ft_end();
	stack_a = check_sequence(argc, argv, stack_a);
	tab = malloc(11 * sizeof(int));
	n = 0;
	while (n < 11)
		tab[n++] = 0;
	set_rank(&stack_a);
	n = nb_flags(argc, argv);
	if (n == 1)
		run_one_flag(argv, &stack_a, &stack_b, tab);
	else if (n == 2)
		run_two_flags(argv, &stack_a, &stack_b, tab);
	else
		run_adaptive(&stack_a, &stack_b, tab);
	free(tab);
	free_stack(stack_a);
}