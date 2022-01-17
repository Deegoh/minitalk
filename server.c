/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:22:08 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/17 14:05:38 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

static void	send_ok(pid_t pid)
{
	kill(pid, SIGUSR1);
	usleep(50);
}

static void	receiver(int signum, siginfo_t *info, void *context)
{
	static int	bit = 128;
	static int	i = 0;
	static char	c = 0;

	(void)context;
	if (signum == SIGUSR1)
	{
		c += bit;
		bit /= 2;
	}
	else if (signum == SIGUSR2)
		bit /= 2;
	if (++i == 8)
	{
		if (c == 6)
			send_ok(info->si_pid);
		else
			write(1, &c, 1);
		bit = 128;
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa_usr_1;
	struct sigaction	sa_usr_2;

	sa_usr_1.sa_flags = SA_SIGINFO;
	sa_usr_1.sa_sigaction = receiver;
	sa_usr_2.sa_flags = SA_SIGINFO;
	sa_usr_2.sa_sigaction = receiver;
	sigaction(SIGUSR1, &sa_usr_1, NULL);
	sigaction(SIGUSR2, &sa_usr_2, NULL);
	ft_printf("srv pid:%d\n", getpid());
	while (1)
		pause();
	return (0);
}
