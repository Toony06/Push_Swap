/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:08:39 by toroman           #+#    #+#             */
/*   Updated: 2025/02/10 16:05:28 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkint(char *av)
{
	int	i;

	i = 0;
	while(av[i])
	{
		if (av[i + 1] == '-' || av[i + 1] == '+')
		{
			ft_printf("Error\n");
			return ;
		}
		if (!ft_isdigit(av[i]) && av[i] != ' ' && av[i] != '-' && av[i] != '+')
		{
			ft_printf("Error\n");
			return ;
		}
		i++;
	}
}
