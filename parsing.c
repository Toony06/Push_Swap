/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:08:39 by toroman           #+#    #+#             */
/*   Updated: 2025/02/27 14:02:29 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkall(t_parse *parse, char **av)
{
	int	i;
	int	num;

	i = 1;
	num = 0;
	parse->tab = ft_strdup("");
	while (av[i])
	{
		parse->tab = ft_strjoin1(parse->tab, av[i]);
		i++;
	}
	parse->str = ft_split(parse->tab, 32);
	while (parse->str[num])
		num++;
	parse->aatoi = malloc(sizeof(int) * num - 1);
	i = 0;
	while (parse->str[i])
	{
		checkint(parse->str[i]);
		parse->aatoi[i] = ft_atoi1(parse->str[i]);
		i++;
	}
	checkduplicate(parse);
}

void	checkint(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+'
			&& str[i] != ' ' && str[i] != '\t')
			ft_error("Error its not digit only");
		if ((str[i] == '-' && !ft_isdigit(str[i + 1]))
			|| (str[i] == '+' && !ft_isdigit(str[i + 1])))
			ft_error("Error operator not viable");
		i++;
	}
}

void	checkduplicate(t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	while (parse->aatoi[i])
	{
		j = i + 1;
		while (parse->aatoi[j])
		{
			if (parse->aatoi[i] == parse->aatoi[j])
				ft_error("Error doublons is detected");
			j++;
		}
		i++;
	}
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}
