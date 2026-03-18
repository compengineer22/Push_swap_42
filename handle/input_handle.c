/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 23:37:46 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/19 00:04:26 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_stack	*insert_stack(t_stack *s, int n)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	if (!temp)
		return (NULL);
	temp->val = n;
	temp->next = s;
	return (temp);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] > s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		else if (s1[i] < s2[i])
		{
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		}
		i++;
	}
	return (0);
}

int	check_dup(char **n)
{
	int	i;
	int	j;

	i = 0;
	delete(n);
	while (n[i])
	{
		j = i + 1;
		while (n[j])
		{
			if (!ft_strcmp(n[i], n[j]) || (is_zero(n[i]) && is_zero(n[j])))
			{
				j = ft_strlen_arr(n);
				while (j >= 0)
					free(n[j--]);
				free(n);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (ft_strlen_arr(n));
}

t_stack	*fill_stack_a(char *s, t_stack *stack)
{
	int		i;
	char	**numbers;
	int		j;

	i = num_of_words(s, ' ') - 1;
	j = 0;
	while (s[j])
	{
		if ((!ft_isdigit(s[j]) && s[j] != ' ' && s[j] != '-')
			|| (s[j] == '-' && !ft_isdigit(s[j + 1])))
			ft_end();
		j++;
	}
	numbers = ft_split(s, ' ');
	if (!check_dup(numbers))
		ft_end();
	if (i < 0)
		ft_end();
	while (i >= 0)
		stack = insert_stack(stack, ft_atoi(numbers[i--], numbers, stack));
	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
	return (stack);
}