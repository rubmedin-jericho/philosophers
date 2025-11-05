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
