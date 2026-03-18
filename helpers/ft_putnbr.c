/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:46:41 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/17 16:46:50 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static int	ftft_putchar(char c)
{
	write(2, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	long	l;
	int		count;

	l = n;
	count = 0;
	if (l < 0)
	{
		count += ftft_putchar('-');
		l *= -1;
	}
	if (l >= 0 && l <= 9)
	{
		count += ftft_putchar(l + '0');
	}
	else
	{
		count += ft_putnbr(l / 10);
		count += ft_putnbr(l % 10);
	}
	return (count);
}
