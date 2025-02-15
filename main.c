/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:22:30 by toroman           #+#    #+#             */
/*   Updated: 2025/02/15 14:35:00 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 2 || !av[1][0])
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (ac == 2)
	{
		av = ft_split(av[i], 32);
	}
	if (av[i])
	{
		checkint(av[i]);
		checkduplicate(av);
	}
}
