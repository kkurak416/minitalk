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

int parse_pid(char *arg)
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

int main (int argc, char **argv)
{
	if (argc != 3 || argv[2][0] =='\0')
		return(0);
}
