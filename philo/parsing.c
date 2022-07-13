/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:56:57 by abouazi           #+#    #+#             */
/*   Updated: 2022/06/12 04:36:12 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

int	ft_isalnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check(int ac, char **av)
{
	int	i;

	if (ac < 6)
	{
		i = 0;
		while (av[++i])
		{
			if (ft_isalnum(av[i]))
				return (printf("Don't enter Characters\n"), 0);
		}
		i = 0;
		while (av[++i])
		{
			if (atoi(av[i]) < 0)
				return (printf("Don't enter negative numbers\n"), 0);
			else if (atoi(av[i]) == 0)
				return (printf("error !\n"), 0);
		}
	}
	return (0);
}
