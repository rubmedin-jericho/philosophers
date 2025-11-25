/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:56:15 by rubmedin          #+#    #+#             */
/*   Updated: 2025/11/05 12:56:51 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_pthread_create(pthread_t *thread, void *philos)
{
	if(pthread_create(thread, NULL, philo_thread, philos) != 0)
	{
		perror("ERROR_CREATE_THREAD\n");
		return (ERROR);
	}
	return (SUCCESS);
}

long ft_atoi(char *str)
{
    int sign;
    long nbr;
    int i;

    sign = 1;
    nbr = 0;
    i = 0;

    if(str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while(str[i])
        nbr = (nbr * 10) + (str[i++] - '0');
    if (nbr > INT_MAX)
        return (INT_MAX);
    if (nbr < INT_MIN)
        return (INT_MIN);
    return (sign * nbr);
}
