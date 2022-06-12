/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inv_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:32:06 by abouazi           #+#    #+#             */
/*   Updated: 2022/06/12 04:35:56 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*supervisor(void *args)
{
	t_philo	*philo;
	int		flag;
	int		i;

	philo = (t_philo *)args;
	while (philo->cont->supe->status)
	{
		i = -1;
		flag = 0;
		while (++i < philo->cont->data->n_philos)
		{
			if (get_time() - (philo + i)->last_eat
				> philo->cont->data->time_die)
			{
				print_action(philo + i, "is died");
				philo->cont->supe->status = false;
			}
			if (philo->cont->data->nom != -1 && (philo + i)->nbr_of_meals
				>= philo->cont->data->nom)
				flag++;
		}
		if (flag == philo->cont->data->n_philos)
			philo->cont->supe->status = false;
	}
	return (NULL);
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	philo->cont->supe->start = get_time();
	while (philo->cont->supe->status)
	{
		print_action (philo, "is thinking");
		pthread_mutex_lock (philo->l_fork);
		print_action (philo, "took the left fork");
		pthread_mutex_lock (philo->r_fork);
		print_action (philo, "took the right fork");
		print_action (philo, "is eating");
		retard_proc (philo->cont->data->time_eat, philo->cont);
		philo->last_eat = get_time();
		pthread_mutex_unlock (philo->l_fork);
		pthread_mutex_unlock (philo->r_fork);
		if (philo->cont->supe->status)
			philo->nbr_of_meals++;
		print_action (philo, "is sleeping");
		retard_proc (philo->cont->data->time_sleep, philo->cont);
	}
	return (NULL);
}

int	inv_philo(t_philo	*philo)
{
	int	i;

	i = -1;
	philo->cont->supe->start = get_time();
	while (++i < philo->cont->data->n_philos)
	{
		(philo + i)->last_eat = get_time();
		if (pthread_create (&(philo + i) \
			->philo_thread, NULL, routine, philo + i))
			return (printf ("error occured while creating thread"), 0);
		pthread_detach((philo + i)->philo_thread);
		usleep(50);
	}
	if (pthread_create(&philo->cont->supe->sup_thread, NULL, supervisor, philo))
		return (printf("error occured while creating thread"), 0);
	if (pthread_join(philo->cont->supe->sup_thread, NULL))
		return (printf ("error occured while joining"), 0);
	i = -1;
	while (++i < philo->cont->data->n_philos)
		pthread_mutex_destroy(&philo->cont->supe->mutex_forks[i]);
	pthread_mutex_destroy(&philo->cont->supe->mutex_print);
	return (0);
}
