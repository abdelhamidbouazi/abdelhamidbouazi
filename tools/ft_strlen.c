/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 00:17:03 by abouazi           #+#    #+#             */
/*   Updated: 2022/07/13 02:03:17 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus/philo_bonus.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
