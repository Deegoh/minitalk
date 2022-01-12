/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:26:54 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/12 20:26:59 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

int		ft_strlen(const char	*str);
int		lennbr(int n);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif