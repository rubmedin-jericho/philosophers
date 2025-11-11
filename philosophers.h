#ifndef	PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>

# define ERROR 1
# define SUCCESS 0
/*PROTOTYPE*/
long ft_atoi(char *str);

typedef struct s_philo
{
    int     philo_n;
    int     die_t;
    int     eat_t;
    int     sleep_t;
	int		forev_d;
    /*OPCIONAL*/
    int     ucaneat_t;
}   t_philo;

#endif
