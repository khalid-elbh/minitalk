/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-bahr <kel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:23:28 by kel-bahr          #+#    #+#             */
/*   Updated: 2025/03/27 11:20:44 by kel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	send_bits(unsigned char m, int pid)
{
	int	i;
	int	bits[8];

	i = 7;
	while (i >= 0)
	{
		bits[i] = m % 2;
		m /= 2;
		i--;
	}
	i = 0;
	while (i < 8)
	{
		if (bits[i])
			ft_kill(pid, SIGUSR1);
		else
			ft_kill(pid, SIGUSR2);
		usleep(50000);
		i++;
	}
}

static void	s_done(int signum)
{
	(void)signum;
	ft_printf("done !\n");
}

static void	handler(int signum)
{
	(void)signum;
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (ac != 3)
		ft_exrror("Error : invalid argument!\n");
	if (!is_valid_number(av[1]))
		ft_exrror("Error : invalid PID!\n");
	pid = ft_atoi(av[1]);
	if (signal(SIGUSR1, handler) == SIG_ERR
		|| signal(SIGUSR2, s_done) == SIG_ERR)
		ft_exrror("Error : signal failed!\n");
	while (av[2][i])
		send_bits(av[2][i++], pid);
	send_bits('\0', pid);
}
