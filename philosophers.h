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
/*PROTOTYPE*/
long ft_atoi(char *str);

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
	pthread_mutex_t	*mutex;
    /*OPCIONAL*/
    int     ucaneat_t;
}   t_philo;

typedef struct	s_mutexs
{
	
}
#endif
