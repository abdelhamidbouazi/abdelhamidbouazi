/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:06:10 by abouazi           #+#    #+#             */
/*   Updated: 2022/06/12 04:36:39 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday (&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	retard_proc(int64_t time_in_ms, t_cont *cnt)
{
	int64_t	start_time;

	start_time = get_time();
	while (cnt->supe->status)
	{
		if (get_time() - start_time >= time_in_ms)
			break ;
		usleep(500);
	}
}

void	print_action(t_philo *philo, char *str)
{
	pthread_mutex_lock (&philo->cont->supe->mutex_print);
	if (philo->cont->supe->status)
		printf("-|%7lld|------|%d|-----%s\n", \
				get_time() - philo->cont->supe->start, philo->philosopher, str);
	pthread_mutex_unlock(&philo->cont->supe->mutex_print);
}
