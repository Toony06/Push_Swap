/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:08:39 by toroman           #+#    #+#             */
/*   Updated: 2025/02/15 14:05:45 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkint(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i + 1] == '-' || av[i + 1] == '+')
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		if (!ft_isdigit(av[i]) && av[i] != ' ' && av[i] != '-' && av[i] != '+')
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	checkduplicate(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
