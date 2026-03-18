/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:46:15 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/17 16:46:23 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int	ft_puthex(unsigned long l, char c)
{
	char	*base;
	int		count;

	count = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (l >= 16)
		count += ft_puthex(l / 16, c);
	count += ft_putchar(base[l % 16]);
	return (count);
}
