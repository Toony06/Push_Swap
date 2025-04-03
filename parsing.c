/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:08:39 by toroman           #+#    #+#             */
/*   Updated: 2025/04/03 15:43:13 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkall(t_parse *parse, char **av)
{
	int	i;

	i = 1;
	parse->num = 0;
	parse->tab = ft_strdup("");
	while (av[i])
	{
		parse->tab = ft_strjoin1(parse->tab, av[i]);
		i++;
	}
	parse->str = ft_split(parse->tab, 32);
	free (parse->tab);
	while (parse->str[parse->num])
		parse->num++;
	parse->aatoi = malloc(sizeof(int) * parse->num + 1);
	i = 0;
	while (parse->str[i])
	{
		parse->aatoi[i] = ft_atoi1(parse->str[i], parse);
		checkint(parse->str[i], parse);
		i++;
	}
	checkduplicate(parse);
	free_arg(parse->str);
}

void	checkint(char *str, t_parse *parse)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+'
			&& str[i] != ' ' && str[i] != '\t')
			ft_error_free("Error its not digit only", parse);
		if ((str[i] == '-' && !ft_isdigit(str[i + 1]))
			|| (str[i] == '+' && !ft_isdigit(str[i + 1])))
			ft_error_free("Error operator not viable", parse);
		i++;
	}
}

void	checkduplicate(t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	while (i < parse->num)
	{
		j = i + 1;
		while (j < parse->num)
		{
			if (parse->aatoi[i] == parse->aatoi[j])
				ft_error_free("Error doublons is detected", parse);
			j++;
		}
		i++;
	}
}

void	ft_error(char *str)
{
	ft_printf(str);
	exit(EXIT_FAILURE);
}

void	ft_error_free(char *str, t_parse *parse)
{
	ft_printf("%s\n", str);
	if (parse->str)
		free_arg(parse->str);
	if (parse->aatoi)
		free(parse->aatoi);
	exit(EXIT_FAILURE);
}
