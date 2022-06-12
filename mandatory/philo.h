/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:52:31 by abouazi           #+#    #+#             */
/*   Updated: 2022/06/12 04:36:29 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>

//S'tructs :
typedef struct timeval	t_time;
typedef struct s_data
{
	int			n_philos;
	long		time_die;
	long		time_eat;
	long		time_sleep;
	int			nom;
}			t_data;

typedef struct s_philo
{
	int					philosopher;
	int					nbr_of_meals;
	long				last_eat;
	pthread_t			philo_thread;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	struct s_container	*cont;
}	t_philo;

typedef struct s_supervisor
{
	long			start;
	bool			status;
	pthread_t		sup_thread;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	mutex_print;
}	t_super;

typedef struct s_container
{
	t_philo	*philo;
	t_data	*data;
	t_super	*supe;
}	t_cont;

//Prototypes :
int		ft_isdigit(int c);
t_data	*ft_init(char **args);
int		ft_check(int ac, char **av);
int		ft_isalnum(char	*data);
void	*routine(void *param);
int64_t	get_time(void);
int		init_data(t_data **data, int ac, char **av);
int		init(t_cont **cont_obj, int ac, char **av);
int		init_philos(t_philo **philo, t_cont *super,
			pthread_mutex_t *mutex_forks, int nphilo);
int		set_inits(t_super **super_obj, int nuphilo);
int		inv_philo(t_philo *philo);
void	*routine(void *args);
void	*supervisor(void *args);
void	print_action(t_philo *philo, char *str);
void	retard_proc(int64_t time_in_ms, t_cont *cnt);
int		ft_atoi(const char *str);
#endif
