/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:22:08 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/07 00:08:34 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <time.h>
#include <stdlib.h>

//void	handle_pause(int signum)
//{
//
//}

void	waiter(int signum)
{
	write(1, &"waiting connection . . .", 24);
	printf(" sig:%d\n", signum);
	pause();
}

void	catcher(int signum)
{
	write(1, &"inside catcher: ", 16);
	printf("%d\n", signum);
}

void	timeout(void)
{
	write(1, &"Timeout: to slow to enter the pid to client\n", 44);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = waiter;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	pid = getpid();
	printf("pid:%d\n", pid);
	pause();
}
