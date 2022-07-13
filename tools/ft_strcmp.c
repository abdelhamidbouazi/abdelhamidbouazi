/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 00:16:53 by abouazi           #+#    #+#             */
/*   Updated: 2022/07/13 02:03:13 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus/philo_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

		i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0'
		&& s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
