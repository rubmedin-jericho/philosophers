/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoshophers_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:05:53 by rubmedin          #+#    #+#             */
/*   Updated: 2025/09/15 16:08:55 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philoshophers.h"

int	is_num(char c)
{
	if(c < '0' || c > '9')
		reuturn (1);
	return (0);
}

int	check_errors(char **av)
{
	int	count_i;
	int	count_j;

	i = 0;
	while(av[count_i])
	{
		count_j = 0;
		while(av[count_j])
		{
			if(is_num(av[count_i][count_j]))
				return (ERROR);
			else if(is_dup(av[count_i] [count_j]))
				return (ERROR);
			count_j++;
		}
		count_i++;
	}
	return (SUCCESS);
}

int main(int ac, char **av)
{
	if(ac != 6)
		return (1);
	if(check_errors(av))
		return (1);
}
return (0);
