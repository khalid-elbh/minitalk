#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void ft_handle(int signal, siginfo_t *info, void *context)
{
	static char c;
	static int read_bit;
	static pid_t	s_pid;

	(void)context;
	if (s_pid != info->si_pid)
	{
		s_pid = info->si_pid;
		c = 0;
		read_bit = 0;
	}
	if (signal == SIGUSR1)
		c =  c * 2 + 1;
	else
		c = c * 2;
	read_bit++;
	if (read_bit == 8)
	{
		write(1, &c, 1);
		read_bit = 0;
		c = 0;
	}
	kill(s_pid, SIGUSR1);
}

int main(int ac, char **av)
{
	pid_t	pid;
	struct sigaction sa;

	(void)av;
	if (ac != 1)
		exit(1);
	pid = getpid();
	printf("%d\n",pid);
	sa.sa_sigaction = ft_handle;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
}
