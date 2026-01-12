/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:58:18 by yopeng            #+#    #+#             */
/*   Updated: 2025/10/10 16:32:54 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define PHILO_MAX 300

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	size_t			start_time;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
}					t_philo;

typedef struct s_program
{
	t_philo			*philos;
	int				dead_flag;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
}					t_program;

//input
int		check_argv_valid(char **argv);
int		check_argv_num(char *argv);
//init
void	init_program(t_program *program, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int philo_num);
void	init_input(t_philo *philo, char **argv);
void	init_philos(t_program *program, t_philo *philos, pthread_mutex_t *forks,
			char **argv);
//thread
int		thread_create(t_program *program, pthread_mutex_t *forks);
void	*monitor(void *arg);
int		check_if_all_ate(t_philo *philos);
int		check_if_die(t_philo *philos);
int		philo_dead(t_philo *philo, size_t time_to_die);
void	print_message(char *str, t_philo *philo, int id);
void	*routine(void *arg);
void	think(t_philo *philo);
void	dream(t_philo *philo);
void	eat(t_philo *philo);
int		dead_loop(t_philo *philo);
//utils
int		ft_atoi(char *str);
void	destroy_all(char *str, t_program *program, pthread_mutex_t *forks);
size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);
int		ft_strlen(char *str);

#endif