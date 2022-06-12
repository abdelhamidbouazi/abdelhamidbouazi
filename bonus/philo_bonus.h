/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 00:15:22 by abouazi           #+#    #+#             */
/*   Updated: 2022/06/12 04:36:52 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_data
{
	int				nop;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				nom;
}	t_data;

typedef struct s_philo
{
	int				philo_number;
	pthread_t		philo_thread;
	int				eat_counter;
	size_t			last_meal_time;
	struct s_tbl	*tbl;
	pid_t			*pid;
	bool			isdied;
}	t_philo;

typedef struct s_sett
{
	size_t			start_time;
	bool			status;
	pthread_t		thread_monitor;
	sem_t			sem_printf;
	sem_t			*sem_forks;
	sem_t			*sem_write;
}	t_sett;

typedef struct s_tbl
{
	t_data	*data;
	t_philo	*philo;
	t_sett	*sett;
}	t_tbl;

int			ft_strlen(const char *s);
int			ft_isnumber(char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(const char *str);
long long	current_timestamp(void);
int			init_tbl_bonus(t_philo **philo, int ac, char **av);
int			philo_start_bonus(t_philo *philo);
void		philo_end(t_philo **philo);
#endif