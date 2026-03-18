/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:03:36 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/19 00:04:33 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	is_dup_number(char *argv[], int argc, int n_flags)
{
	int	i;
	int	j;

	i = n_flags + 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i], NULL, NULL) == ft_atoi(argv[j], NULL, NULL))
				ft_end();
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	*separate_numbers(int argc, char *argv[], t_stack *s, int n_flags)
{
	int	i;

	i = argc - 1;
	check_dup_sep(argv + n_flags + 1);
	while (i >= 1 + n_flags)
	{
		if (argv[i][0] == '-' || argv[i][0] == '+')
		{
			if (!is_numeric(&argv[i][1]) || !argv[i][1])
			{
				free_stack(s);
				ft_end();
			}
		}
		else if (!is_numeric(argv[i]))
		{
			free_stack(s);
			ft_end();
		}
		is_dup_number(argv, argc, n_flags);
		s = insert_stack(s, ft_atoi(argv[i], NULL, s));
		i--;
	}
	return (s);
}

int	is_valid_flag(char *s)
{
	return (!ft_strcmp(s, "--bench") || !ft_strcmp(s, "--simple")
		|| !ft_strcmp(s, "--medium") || !ft_strcmp(s, "--complex")
		|| !ft_strcmp(s, "--adaptive"));
}

int	nb_flags(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (is_valid_flag(argv[1]))
	{
		i++;
		if (argc > 2 && is_valid_flag(argv[2]))
			i++;
	}
	if (i == 2 && !ft_strcmp(argv[1], argv[2]))
		ft_end();
	return (i);
}

t_stack	*check_sequence(int argc, char *argv[], t_stack *stack_a)
{
	int	n_flags;

	n_flags = nb_flags(argc, argv);
	if (n_flags == 2)
	{
		if (comp_flag(argv[1]) && comp_flag(argv[2]))
			ft_end();
		if (argc < 4)
			ft_end();
		else if (argc == 4)
			stack_a = fill_stack_a(argv[3], stack_a);
		else
			stack_a = separate_numbers(argc, argv, stack_a, n_flags);
	}
	else if (n_flags == 1)
	{
		if (argc == 3)
			stack_a = fill_stack_a(argv[2], stack_a);
		else if (argc > 3)
			stack_a = separate_numbers(argc, argv, stack_a, n_flags);
		else
			ft_end();
	}
	else
		stack_a = handle_no_flags(argc, argv, n_flags, stack_a);
	return (stack_a);
}