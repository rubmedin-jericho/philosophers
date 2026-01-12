#ifndef	PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>

# define ERROR 1
# define SUCCESS 0

	/*PROTOTYPES*/
	long	ft_atoi(char *str);
	int		ft_pthread_create(pthread_t *thread, void *philos);
	void	*philo_thread(void *arg);

typedef struct s_mutex
{
	pthread_mutex_t fork;
	pthread_mutex_t fork_right;
	pthread_mutex_t eat_time;
	pthread_mutex_t die;
}	t_mutex;

typedef struct s_philo
{
	int		philo_n; //nombre del philo.
	int		die_t; //tiempo que tiene de vida.
	int		eat_t; //tiempo que esta comiendo.
	int		sleep_t; //tiempo que esta durmiendo.
	int		num_philos; //numero de philos.
	long	global_t; //tiempo en milisegundos.
	/*OPCIONAL*/
	int     ucaneat_t; //numero de veces que el philo puede comer.
	t_mutex *mutex_l;
}	t_philo;
#endif
