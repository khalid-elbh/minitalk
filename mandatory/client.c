#include <unistd.h>
#include <limits.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>


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

int g_sent;

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
void resend(int signal)
{
	if (signal == 10)
		g_sent = 1;
}
void send_bits(char m, int pid)
{
	int i = 7;
	int bits[8];
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
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_sent == 0)
			usleep(20);
		g_sent = 0;
		i++;
	}
}

int main(int ac, char **av)
{
	pid_t pid;
	char *message;
	int i = 0;

	if(ac != 3)
		exit(1);
	if(!is_valid_number(av[1]))
		exit(1);
	pid = ft_atoi(av[1]);
	message = av[2];
	signal(SIGUSR1, resend);
	while(av[2][i])
		send_bits(av[2][i++], pid);
	send_bits('\0', pid);
}
