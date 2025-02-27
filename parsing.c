/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:08:39 by toroman           #+#    #+#             */
/*   Updated: 2025/02/27 18:07:54 by tony             ###   ########.fr       */
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
		checkint(parse->str[i], parse);
		parse->aatoi[i] = ft_atoi1(parse->str[i]);
		i++;
	}
	checkduplicate(parse);
}

void	checkint(char *str, t_parse *parse)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+'
			&& str[i] != ' ' && str[i] != '\t')
			ft_error("Error its not digit only", parse);
		if ((str[i] == '-' && !ft_isdigit(str[i + 1]))
			|| (str[i] == '+' && !ft_isdigit(str[i + 1])))
			ft_error("Error operator not viable", parse);
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
				ft_error("Error doublons is detected", parse);
			j++;
		}
		i++;
	}
}

void	ft_error(char *str, t_parse *parse)
{
	ft_printf(str);
	if (parse->str)
		ft_free(parse->str);
	if (parse->tab)
		free(parse->tab);
	exit(EXIT_FAILURE);
}

void	ft_free(char **tab)
{
	int	i;

	if (!tab)
		return;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
