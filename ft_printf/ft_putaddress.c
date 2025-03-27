/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-bahr <kel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:12:35 by kel-bahr          #+#    #+#             */
/*   Updated: 2025/01/05 10:03:29 by kel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(unsigned long nb)
{
	int	count;

	if (nb == 0)
		return (write(1, "(nil)", 5));
	count = 0;
	count += write(1, "0x", 2);
	count += ft_puthexa(nb, 'x', 0);
	return (count);
}
