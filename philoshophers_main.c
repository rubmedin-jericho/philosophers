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
	if(ac != 6)
	{
		printf("FEW ARGUMENTS\n");
		return (1);
	}
	if(check_errors(av))
		return (1);
	printf("FUNCIONA\n");
	return (0);
}
