/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:21:09 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/12 20:26:59 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	send_str(char *str, pid_t srv_pid, int nbrarg, int maxarg)
{
	int	j;

	j = 0;
	while (str[j])
		atob(str[j++], srv_pid);
	if (nbrarg < maxarg - 1)
		atob(' ', srv_pid);
}

void	stop(int signum)
{
	(void)signum;
	write(1, &"stop pros", 9);
}

int	main(int ac, char *av[])
{
	pid_t	srv_pid;
	pid_t	clt_pid;
	int		i;

	if (ac < 3 || ft_atoi(av[1]) < 0)
	{
		write(1, "usage: ./client [srv-pid] [msg]\n", 34);
		return (1);
	}
	srv_pid = ft_atoi(av[1]);
	i = 1;
	while (av[++i])
		send_str(av[i], srv_pid, i, ac);
	atob(6, srv_pid);
	clt_pid = getpid();
	send_str(ft_itoa(clt_pid), srv_pid, 0, 0);
	atob(6, srv_pid);
	while (1)
	{
		signal(SIGUSR1, stop);
		pause();
	}
	return (0);
}
