/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-bahr <kel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:24:29 by kel-bahr          #+#    #+#             */
/*   Updated: 2025/01/05 10:03:53 by kel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	if (s == NULL)
		return (write(1, "(null)", 6));
	count = 0;
	i = 0;
	while (i[s])
		count += ft_putchar((i++)[s]);
	return (count);
}
