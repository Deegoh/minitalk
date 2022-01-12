/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:22:08 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/12 21:00:57 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>
#include <string.h>

char	*join(const char *s1, const char *s2)
{
	char	*result;

	result = malloc(strlen(s1) + strlen(s2) + 1);
	if (result)
	{
		strcpy(result, s1);
		strcat(result, s2);
	}
	return (result);
}

void	send_ok(char c, int ok)
{
//	pid_t		clt_pid;
	static char	*tmp_pid = "";
	static int	i = 0;

	if (c != 6)
		tmp_pid = join(tmp_pid, &c);
	if (c == 6 && ok)
	{
		write(1, &tmp_pid, 6);
//		kill(dec, SIGUSR1);
	}
	i++;
}

void	receiver(int signum)
{
	static int	bit = 128;
	static int	i = 0;
	static char	c = 0;
	static char	ok = 0;

	if (signum == SIGUSR1)
	{
		c += bit;
		bit /= 2;
	}
	else if (signum == SIGUSR2)
		bit /= 2;
	i++;
	if (i == 8)
	{
		if (c == 6 || ok)
		{
			send_ok(c, ok);
			ok = 1;
		}
		else
			write(1, &c, 1);
		bit = 128;
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("srv pid:%d\n", pid);
	while (1)
	{
		signal(SIGUSR1, receiver);
		signal(SIGUSR2, receiver);
		pause();
	}
	return (0);
}
