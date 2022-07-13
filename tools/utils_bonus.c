/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 00:17:17 by abouazi           #+#    #+#             */
/*   Updated: 2022/07/13 02:03:26 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus/philo_bonus.h"

long long	current_timestamp(void)
{
	struct timeval	te;
	long long		milliseconds;

	gettimeofday(&te, NULL);
	milliseconds = (te.tv_sec * 1000) + (te.tv_usec / 1000);
	return (milliseconds);
}

int	init_data(t_data **data, int ac, char **av)
{
	t_data	*tmp;

	tmp = (t_data *)malloc(sizeof(t_data));
	if (!tmp)
		return (printf("Allocation Failed\n"), -1);
	tmp->nop = ft_atoi(av[1]);
	tmp->time_to_die = ft_atoi(av[2]);
	tmp->time_to_eat = ft_atoi(av[3]);
	tmp->time_to_sleep = ft_atoi(av[4]);
	tmp->nom = -1;
	if (ac == 6)
		tmp->nom = ft_atoi(av[5]);
	*data = tmp;
	return (0);
}

int	init_sett(t_sett **sett, int nop)
{
	t_sett	*tmp;

	tmp = (t_sett *)malloc(sizeof(t_sett));
	if (!tmp)
		return (printf("Allocation Failed\n"), -1);
	tmp->start_time = 0;
	tmp->status = true;
	sem_unlink("/sem_write");
	sem_unlink("/sem_forks");
	tmp->sem_write = sem_open("/sem_write", O_CREAT, 0644, 1);
	tmp->sem_forks = sem_open("/sem_forks", O_CREAT, 0644, nop);
	if (tmp->sem_write == SEM_FAILED || tmp->sem_forks == SEM_FAILED)
		return (printf("Failed To Open Semaphore\n"), -1);
	*sett = tmp;
	return (0);
}

int	init_tbl_bonus(t_philo **philo, int ac, char **av)
{
	t_philo	*tmp;

	tmp = (t_philo *)malloc(sizeof(t_philo));
	if (!tmp)
		return (printf("Allocation Failed\n"), -1);
	if (init_data(&tmp->tbl->data, ac, av) == -1
		|| init_sett(&tmp->tbl->sett, tmp->tbl->data->nop) == -1)
		return (-1);
	tmp->pid = (pid_t *)malloc(sizeof(pid_t) * tmp->tbl->data->nop);
	if (!tmp->pid)
		return (printf("Allocation Failed\n"), -1);
	tmp->isdied = false;
	tmp->eat_counter = 0;
	*philo = tmp;
	return (0);
}
