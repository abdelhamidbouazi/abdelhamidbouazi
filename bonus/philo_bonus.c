/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 00:12:03 by abouazi           #+#    #+#             */
/*   Updated: 2022/06/12 04:36:49 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_errors(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_isnumber(av[i]))
		{
			printf("Invalid Arguments!\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_create_pids(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->tbl->data->nop)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
		{
			printf("Can't create a child process");
			exit(EXIT_FAILURE);
		}
		if (philo->pid[i] == 0)
		{
			philo->philo_number = i + 1;
			philo->last_meal_time = current_timestamp();
			philo_start_bonus(philo);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (ac < 5 || ac > 6)
	{
		write(STDERR_FILENO, "Invalid Arguments!\n", 20);
		return (EXIT_FAILURE);
	}
	if (check_errors(av))
		return (EXIT_FAILURE);
	if (init_tbl_bonus(&philo, ac, av) == -1)
		return (EXIT_FAILURE);
	philo->tbl->sett->start_time = current_timestamp();
	ft_create_pids(philo);
	philo_end(&philo);
	exit(EXIT_SUCCESS);
}
