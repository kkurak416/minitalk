/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:39:38 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/05/08 13:40:17 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ack_handler(int sig)
{
	(void)sig;
	write(1, "Message recived\n", 16);
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c & (1 << i)) > 0)
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		usleep(700);
		i--;
	}
}

int	parse_pid(char *arg)
{
	int	i;
	int	pid;

	i = 0;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else
			return (-1);
	}
	pid = ft_atoi(arg);
	if (pid <= 0)
		return (-1);
	return (pid);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3 || argv[2][0] == '\0')
		return (0);
	signal(SIGUSR1, ack_handler);
	pid = parse_pid(argv[1]);
	if (pid == -1)
		return (0);
	while (argv[2][i] != '\0')
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
