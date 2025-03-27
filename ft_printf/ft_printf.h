/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-bahr <kel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:18:13 by kel-bahr          #+#    #+#             */
/*   Updated: 2025/01/05 10:01:49 by kel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putunbr(unsigned int nb);
int	ft_putaddress(unsigned long nb);
int	ft_printf(const char *f, ...);
int	ft_puthexa(unsigned long nb, char c, int add);
int	ft_putnbr(int nb);

#endif
