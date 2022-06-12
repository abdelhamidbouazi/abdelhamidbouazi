/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 08:20:38 by abouazi           #+#    #+#             */
/*   Updated: 2022/06/12 04:35:46 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data **data, int ac, char **av)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!*data)
		return (0);
	(*data)->n_philos = ft_atoi(av[1]);
	(*data)->time_die = ft_atoi(av[2]);
	(*data)->time_eat = ft_atoi(av[3]);
	(*data)->time_sleep = ft_atoi(av[4]);
	(*data)->nom = -1;
	if (ac == 6)
		(*data)->nom = ft_atoi(av[5]);
	return (0);
}

int	set_inits(t_super **super_obj, int nuphilo)
{
	int		i;
	t_super	*super;

	super = (t_super *)malloc(sizeof(t_super));
	if (!super)
		return (0);
	super->start = 0;
	super->status = true;
	super->mutex_forks = malloc(sizeof(pthread_mutex_t) * nuphilo);
	if (!super->mutex_forks)
		return (0);
	i = -1;
	while (++i < nuphilo)
		if (pthread_mutex_init(super->mutex_forks + i, NULL))
			return (-1);
	if (pthread_mutex_init(&super->mutex_print, NULL))
		return (-1);
	*super_obj = super;
	return (0);
}

int	init_philos(t_philo **philo, t_cont *super, \
	pthread_mutex_t *mutex_forks, int nphilo)
{	
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * nphilo);
	if (!*philo)
		return (0);
	i = -1;
	while (++i < nphilo)
	{
		(*philo + i)->philosopher = i + 1;
		(*philo + i)->nbr_of_meals = 0;
		(*philo + i)->last_eat = 0;
		(*philo + i)->cont = super;
		(*philo + i)->l_fork = mutex_forks + i;
		(*philo + i)->r_fork = mutex_forks + ((i + 1) % nphilo);
	}
	return (0);
}

int	init(t_cont **cont_obj, int ac, char **av)
{
	t_cont	*cnt;

	cnt = (t_cont *)malloc(sizeof(t_cont));
	if (!cnt)
		return (0);
	if (init_data(&cnt->data, ac, av) == -1)
		return (-1);
	if (set_inits(&cnt->supe, cnt->data->n_philos) == -1)
		return (-1);
	if (init_philos(&cnt->philo, cnt, \
		cnt->supe->mutex_forks, cnt->data->n_philos) == -1)
		return (-1);
	*cont_obj = cnt;
	return (0);
}
