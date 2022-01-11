/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:21:09 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/11 11:49:39 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

static int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	return (res * sign);
}

void	atob(char c, pid_t pid)
{
	int	bit;

	bit = 8;
	while (bit)
	{
		bit--;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else if (c)
			kill(pid, SIGUSR2);
		usleep(20);
	}
}

int	main(int ac, char *av[])
{
	pid_t	pid;
	char	*str;
	int		i;

	if (ac != 3 || atoi(av[1]) < 0)
	{
		write(1, "usage: ./client [srv-pid] [msg]\n", 34);
		return (1);
	}
	pid = ft_atoi(av[1]);
	str = av[2];
	i = 0;
	while (str[i])
		atob(str[i++], pid);
	return (0);
}
