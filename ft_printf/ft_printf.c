/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-bahr <kel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:31:00 by kel-bahr          #+#    #+#             */
/*   Updated: 2025/01/05 10:02:31 by kel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_the_format(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		count = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count = ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_puthexa(va_arg(args, unsigned int), c, 1);
	else if (c == 'p')
		count = ft_putaddress(va_arg(args, unsigned long));
	else if (c == '%')
		return (write(1, "%", 1));
	return (count);
}

int	ft_printf(const char *f, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!f)
		return (-1);
	count = 0;
	i = 0;
	va_start(args, f);
	while (f[i])
	{
		if (f[i] == '%')
		{
			if (f[++i] == '\0')
				return (-1);
			count += get_the_format(args, f[i]);
		}
		else
			count += ft_putchar(f[i]);
		i++;
	}
	return (count);
}
