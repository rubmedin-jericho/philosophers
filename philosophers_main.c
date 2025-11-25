/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:05:53 by rubmedin          #+#    #+#             */
/*   Updated: 2025/09/15 16:08:55 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
long get_time_ms(void)
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

static int	look_forks(t_philo *philos)
{
	int	philo_n;
	int	philo_l;


	pthread_mutex_lock(philos->mutex_l->mutex_fork);
	if((philos->philo_n - 1) == 0)
	{
		philo_l = philos[philos->num_philos].fork;
		if(!philos->fork && !philo_l)
		{
			pthread_mutex_unlock(philos->mutex_l->mutex_fork);
			return (philos->num_philos);
		}
	}
	philo_n = philos->philo_n - 1;
	philo_l = philos[philo_n - 1].fork;
	if(!philos->fork && !philo_l)
	{
		pthread_mutex_unlock(philos->mutex_l->mutex_fork);
		return (ERROR);
	}
	pthread_mutex_unlock(philos->mutex_l->mutex_fork);
	return (SUCCESS);
}

static void	rutine(t_philo *philos)
{
	int	philo_before;
	int	is_active;

	is_active = look_forks(philos);
	//printf("\t[look_forks] : %i\n\t[num_philos] : %i\n", is_active, philos->num_philos);
	if(is_active == philos->num_philos) 
	{
		pthread_mutex_lock(philos->mutex_l->mutex_fork);
		philos->fork = 1;	
		philos[philos->num_philos].fork = 1;
		printf("[%ld] [philo_%d] has taken a fork\n", get_time_ms() - philos->global_t, philos->philo_n);
		printf("[%ld] [philo_%d] is eating\n", get_time_ms() - philos->global_t, philos->philo_n);
		usleep((philos->eat_t * 1000));
		philos->fork = 0;
		philos[philos->num_philos].fork = 0;
		pthread_mutex_unlock(philos->mutex_l->mutex_fork);
	}
	else if(is_active)
	{
		pthread_mutex_lock(philos->mutex_l->mutex_fork);
		philos->fork = 1;	
		philos[philos->num_philos].fork = 1;
		printf("[%ld] [philo_%d] has taken a fork\n", get_time_ms() - philos->global_t, philos->philo_n);
		printf("[%ld] [philo_%d] is eating\n", get_time_ms() - philos->global_t, philos->philo_n);
		usleep((philos->eat_t * 1000));
		philos->fork = 0;	
		philos[philos->num_philos].fork = 0;
		pthread_mutex_unlock(philos->mutex_l->mutex_fork);
	}
	//usleep(500);
}

static int	monitoring_forev_d(t_philo **philos, int num_philo)
{
	int	i;

	i = 0;
	while(i < num_philo)
	{
		pthread_mutex_lock(((*philos)[i]).mutex_l->mutex_fork);	
		if((*philos)[i].forev_d == 1)
			return (1);
		pthread_mutex_unlock((*philos)[i].mutex_l->mutex_fork);
		i++;
		usleep(500);
	}
	return (0);
}

//static void	make_rutine(t_philo **philos, int num_philo)
//{
//	int	monitor;
//
//	monitor = monitoring_forev_d(*philos, num_philo);
//	while(!monitor)
//	{
//		rutine(*philos);
//		monitor = monitoring_forev_d(*philos, num_philo);
//	}
//}

static void	save_memory(t_philo **philos, int num_philo)
{
	int	i;

	*philos = malloc(sizeof(**philos) * num_philo);
	i = 0;
	while(i < num_philo)
	{
		philos[0][i].forev_d = 0;
		i++;
	}
}

static int ft_limits(int nbr)
{
    if(nbr > INT_MAX || nbr < INT_MIN)
        return (1);
    return (0);
}

int	is_sign_dup(char c, int *flag)
{
	if(c < '0' || c > '9')
		*flag += 1;
	if(*flag > 1)
		return (1);
	return (0);
}

int	is_num(char c)
{
	if(c >= '0' && c <= '9' || c == '-' || c == '+')
		return (0);
	return (1);
}

t_philo init_philo(int ac, char **av, int num_philo, t_mutex *mutex)
{
    t_philo philo;
    int num_die;
    int num_eat;
    int num_sleep;
    int num_ucaneat;
	int	num_philos;

    num_die = ft_atoi(av[2]);
    num_eat = ft_atoi(av[3]);
    num_sleep = ft_atoi(av[4]);
	num_philos = ft_atoi(av[1]);
    num_ucaneat = 0;
    if(ac == 6)
        num_ucaneat = ft_atoi(av[5]);
    philo.philo_n = num_philo + 1;
    philo.die_t = num_die;
    philo.eat_t = num_eat;
    philo.sleep_t = num_sleep; 
    philo.ucaneat_t = num_ucaneat;
	philo.forev_d = 0;
	philo.global_t = get_time_ms();
	philo.fork = 0;
	philo.num_philos = num_philos;
	philo.mutex_l = mutex;
    return (philo);
}

static void print_struct(t_philo philo)
{
    printf("\n[philo_%d]\n\t[die_philo] : %i\n\t[eat_t] : %i\n\t[sleep_t] : %i\n\t[ucaneat_t] : %i\n\t[forev_d] : %i\n", philo.philo_n, philo.die_t, philo.eat_t, philo.sleep_t, philo.ucaneat_t, philo.forev_d);
}

void *philo_thread(void *arg) {

    t_philo *philo;
	int	i;

	i = 0;
    philo = (t_philo *)arg;
//    print_struct(*philo);
	//while(i < 10)
	while(!philo->forev_d)
	{
//		if(i > 99)
//			philo->forev_d = 1;
		rutine(philo);
		usleep(100);
		//i++;
	}
	//make_rutine(&philos, num_philo);
	return (NULL);
}

static int    philosophers(int ac, char **av, int *init_bucle, 
	t_mutex *mutex)
{
    int i;
    int num_philo;
	int	monitor;
    t_philo *philos;
    pthread_t thread;

    i = 0;
    num_philo = ft_atoi(av[1]);
    if(ft_limits(num_philo))
        return (ERROR);
    philos = malloc(sizeof(t_philo) * num_philo);
    while(i < num_philo)
    {
        philos[i] = init_philo(ac, av, i, mutex);
        //CREAR THREADS
		if(ft_pthread_create(&thread, (void *)&philos[i]))
			return (ERROR);
        i++;
		usleep(500);
    }
	monitor = 0;
	while(!monitor)
	{
		monitor = monitoring_forev_d(&philos, num_philo);
		usleep(500);
	}
    //HACE FALTA HACER FREE DE NUM_PHILO
    return (SUCCESS);
}

int	check_errors(char **av)
{
	int	count_i;
	int	count_j;
	int	flag;

	count_i = 1;
	while(av[count_i])
	{
		count_j = 0;
		flag = 0;
		while(av[count_i] [count_j])
		{
			if(is_num(av[count_i][count_j]))
			{ 	
				printf("ERROR NO NUM\n");
				return (ERROR);
			}	
			else if(is_sign_dup(av[count_i] [count_j], &flag))
			{
				printf("ERROR DUPLICADO\n");
				return (ERROR);
			}
			count_j++;
		}
		count_i++;
	}
	return (SUCCESS);
}

int main(int ac, char **av)
{
	int init_bucle;
	t_mutex	mutex;

	pthread_mutex_init(mutex.mutex_die, NULL);
	pthread_mutex_init(mutex.mutex_fork, NULL);
	init_bucle = 1;
	if(ac < 5 || ac > 6)
	{
		printf("ERROR ARGUMENTS\n");
		return (1);
	}
	if(check_errors(av))
		return (1);
    if(philosophers(ac, av, &init_bucle, &mutex))
        return (1);
	printf("FUNCIONA\n");
	return (0);
}
