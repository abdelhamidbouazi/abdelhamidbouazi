/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:55:40 by abouazi          #+#    #+#             */
/*   Updated: 2022/06/12 04:36:17 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_cont	*cont;

	if ((argc != 5 && argc != 6))
		return (printf("Too Many Or Less Arguments!\n"), 0);
	if ((ft_check(argc, argv) == -1))
		return (-1);
	if (init(&cont, argc, argv) == -1)
		return (-1);
	if (inv_philo(cont->philo) == -1)
		return (-1);
	return (0);
}
