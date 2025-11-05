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
	if((c >= '0' || c == ('-' || '+')) || (c <= '9' || c == ('-' || '+')))
		return (0);
	return (1);
}

t_philo init_philo(int ac, char **av, int num_philo)
{
    t_philo philo;
    int num_die;
    int num_eat;
    int num_sleep;
    int num_ucaneat;

    num_die = ft_atoi(av[2]);
    num_eat = ft_atoi(av[3]);
    num_sleep = ft_atoi(av[4]);
    num_ucaneat = 0;
    if(ac == 6)
        num_ucaneat = ft_atoi(av[5]);
    philo.philo_n = num_philo + 1;
    philo.die_t = num_die;
    philo.eat_t = num_eat;
    philo.sleep_t = num_sleep; 
    philo.ucaneat_t = num_ucaneat;
    return (philo);
}

static void print_struct(t_philo philo)
{
    printf("\n[philo_%d]\n\t[die_philo] : %i\n\t[eat_t] : %i\n\t[sleep_t] : %i\n\t[ucaneat_t] : %i\n", philo.philo_n, philo.die_t, philo.eat_t, philo.sleep_t, philo.ucaneat_t);
}

static void *philo_thread(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    print_struct(*philo);
}
static int    philosophers(int ac, char **av)
{
    int i;
    int num_philo;
    t_philo *philos;
    pthread_t thread;

    i = 0;
    num_philo = ft_atoi(av[1]);
    if(ft_limits(num_philo))
        return (1);
    philos = malloc(sizeof(t_philo) * num_philo);
    while(i < num_philo)
    {
        philos[i] = init_philo(ac, av, i);
        //CREAR THREADS
        pthread_create(&thread, NULL, philo_thread, (void *)&philos[i]);
        i++;
    }
    //HACE FALTA HACER FREE DE NUM_PHILO
    return (0);
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
	if(ac < 5 || ac > 6)
	{
		printf("ERROR ARGUMENTS\n");
		return (1);
	}
	if(check_errors(av))
		return (1);
    if(philosophers(ac, av))
        return (1);
	printf("FUNCIONA\n");
	return (0);
}
