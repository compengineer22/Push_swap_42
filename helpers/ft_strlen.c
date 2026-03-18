/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:48:16 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/17 16:48:21 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stddef.h>
#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_strlen_arr(char **s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}
