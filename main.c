/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:22:30 by toroman           #+#    #+#             */
/*   Updated: 2025/02/16 16:14:28 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_parse	parse;

	if (ac < 2 || !av[1][0])
	{
		ft_printf("Error its not valid\n");
		exit(EXIT_FAILURE);
	}
	checkall(&parse, av);
}
char	*ft_strjoin1(char const *s1, char const *s2)
{
	int			i;
	int			j;
	char		*result;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (0);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	if (s1[0])
		result[i++] = ' ';
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
