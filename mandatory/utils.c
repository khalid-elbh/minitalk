/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-bahr <kel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:13:17 by kel-bahr          #+#    #+#             */
/*   Updated: 2025/03/27 11:13:27 by kel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_exrror(char *error)
{
	int	i;

	i = 0;
	while (error[i])
	{
		write (2, &error[i], 1);
		i++;
	}
	exit(1);
}

void	ft_kill(pid_t pid, int signum)
{
	if (kill(pid, signum) < 0)
	{
		write (2, "Error : kill failed!\n", 22);
		exit(1);
	}
}

int	is_valid_number(char *str)
{
	long	value;
	int		i;

	i = 0;
	value = 0;
	if (!str || !*str)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
		if (value > INT_MAX)
			return (0);
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return ((int)(res * sign));
}
