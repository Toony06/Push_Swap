/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:53:24 by tony              #+#    #+#             */
/*   Updated: 2025/04/03 15:39:56 by toroman          ###   ########.fr       */
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
		ft_error_free("Error limit int", parse);
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
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
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
	free(s1);
	return (result);
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_printf("%d\n", (stack)->data);
		stack = (stack)->next;
	}
}

void	free_stack(t_node *stack)
{
	t_node	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

t_node	*find_min(t_node *stack)
{
	t_node	*smallest_node;
	t_node	*current_node;

	smallest_node = stack;
	current_node = stack;
	while (current_node)
	{
		if (smallest_node->data > current_node->data)
			smallest_node = current_node;
		current_node = current_node->next;
	}
	return (smallest_node);
}
