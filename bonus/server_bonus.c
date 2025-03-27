/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-bahr <kel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:24:51 by kel-bahr          #+#    #+#             */
/*   Updated: 2025/03/27 11:16:54 by kel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_handle(int signal, siginfo_t *info, void *context)
{
	static char		c;
	static int		read_bit;
	static pid_t	s_pid;

	(void)context;
	if (s_pid != info->si_pid)
	{
		s_pid = info->si_pid;
		c = 0;
		read_bit = 0;
	}
	if (signal == SIGUSR1)
		c = c * 2 + 1;
	else
		c = c * 2;
	read_bit++;
	if (read_bit == 8)
	{
		if (c == '\0')
			ft_kill(s_pid, SIGUSR2);
		write(1, &c, 1);
		read_bit = 0;
		c = 0;
	}
	ft_kill(s_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
		exit(1);
	pid = getpid();
	ft_printf("PID :%d\n", pid);
	sa.sa_sigaction = ft_handle;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) < 0 || sigaction(SIGUSR2, &sa, NULL) < 0)
		ft_exrror("Error : sigaction failed!\n");
	while (1)
		pause();
}
