/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsrour <hsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:45:25 by hsrour            #+#    #+#             */
/*   Updated: 2026/03/17 16:45:38 by hsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include <stdio.h>

int	ft_format(char c, va_list args)
{
	unsigned long	l;

	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
	{
		l = (unsigned long)va_arg(args, void *);
		if (!l)
			return (write (1, "(nil)", 5));
		write(1, "0x", 2);
		return (2 + ft_puthex(l, 'x'));
	}
	if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbru(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c));
	return (0);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				count += write(fd, &format[i], 1);
			else
				count += ft_format(format[i], args);
		}
		else
			count += write(fd, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
