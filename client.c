/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:21:09 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/17 13:55:39 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

static void	atob(char c, pid_t pid)
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
		usleep(50);
	}
}

static void	send_str(char *str, pid_t srv_pid, int nbrarg, int maxarg)
{
	int	j;

	j = 0;
	while (str[j])
		atob(str[j++], srv_pid);
	if (nbrarg < maxarg - 1)
		atob(' ', srv_pid);
}

static void	ack_stop(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, &"ack completed\n", 15);
		exit (0);
	}
}

int	main(int ac, char *av[])
{
	pid_t	srv_pid;
	int		i;

	if (ac < 3 || ft_atoi(av[1]) < 0)
	{
		write(1, "usage: ./client [srv-pid] [msg]\n", 33);
		return (1);
	}
	signal(SIGUSR1, ack_stop);
	srv_pid = ft_atoi(av[1]);
	i = 1;
	while (av[++i])
		send_str(av[i], srv_pid, i, ac);
	atob(6, srv_pid);
	return (0);
}
