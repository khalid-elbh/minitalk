/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-bahr <kel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:22:24 by kel-bahr          #+#    #+#             */
/*   Updated: 2025/01/05 10:01:30 by kel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long nb, char c, int add)
{
	int				cont;
	unsigned long	mod_16;

	cont = 0;
	if (add)
		nb = (unsigned int)nb;
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb > 15)
		cont += ft_puthexa(nb / 16, c, add);
	mod_16 = nb % 16;
	if (mod_16 < 10)
		cont += ft_putchar(mod_16 + '0');
	else
	{
		if (c == 'x')
			cont += ft_putchar((mod_16 - 10) + 'a');
		else
			cont += ft_putchar((mod_16 - 10) + 'A');
	}
	return (cont);
}
