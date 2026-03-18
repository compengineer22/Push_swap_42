/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:02:36 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/17 17:02:45 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	comp_flag(char *s)
{
	return (!ft_strcmp(s, "--simple")
		|| !ft_strcmp(s, "--medium") || !ft_strcmp(s, "--complex")
		|| !ft_strcmp(s, "--adaptive"));
}

void	ft_end(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

t_stack	*handle_no_flags(int argc, char *argv[], int n_flags, t_stack *stack_a)
{
	if (n_flags == 0)
	{
		if (argc == 2)
			stack_a = fill_stack_a(argv[1], stack_a);
		else
			stack_a = separate_numbers(argc, argv, stack_a, n_flags);
	}
	return (stack_a);
}

int	is_numeric(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

float	compute_disorder(t_stack *a)
{
	float	mistakes;
	float	total_pairs;
	t_stack	*i;
	t_stack	*j;

	i = a;
	mistakes = 0;
	total_pairs = 0;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs += 1;
			if (i->val > j->val)
				mistakes += 1;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes / total_pairs);
}
