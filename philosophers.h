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
	pthread_mutex_t	mutex_die;
	pthread_mutex_t	mutex_fork;
}	t_mutex;

typedef struct s_philo
{
    int		philo_n;
	int		flag_start;
    int		die_t;
    int		eat_t;
    int		sleep_t;
	int		forev_d;
	int		fork;
	int		num_philos;
	long	global_t;
	t_mutex *mutex_l;
    /*OPCIONAL*/
    int     ucaneat_t;
}	t_philo;
#endif
