/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkurowsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:40:25 by kkurowsk          #+#    #+#             */
/*   Updated: 2025/05/08 13:40:40 by kkurowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int				bit_index;
	static unsigned char	c = 0;

	(void)context;
	bit_index = 0;
	if (sig == SIGUSR2)
		c |= (1 << (7 - bit_index));
	bit_index++;
	if (bit_index == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			write(1, "\n", 1);
		kill(info->si_pid, SIGUSR1);
		c = 0;
		bit_index = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	printf("%d\n", pid);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
