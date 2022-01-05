/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:22:08 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/05 15:29:48 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	int		pid;
	char	input = '\0';

	pid = getpid();
	printf("%d\n", pid);
//	while (1)
//	{
//		sleep(20);
//		if (input == 'x')
//			break ;
//		write(0, &input, 1);
//		printf("%c\n", input);
//	}
//	write(1, &pid, 5);
}
