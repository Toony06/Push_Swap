/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:53:24 by tony              #+#    #+#             */
/*   Updated: 2025/02/27 18:18:40 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

long	ft_atoi1(char *nptr, t_parse *parse)
{
	int		i;
	long	result;
	int		signe;

	i = 0;
	result = 0;
	signe = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	if (result * signe < INT_MIN || result * signe > INT_MAX)
		ft_error("Error limit int", parse);
	return (result * signe);
}

char	*ft_strjoin1(char *s1, char *s2)
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
	free (s1);
	return (result);
}
