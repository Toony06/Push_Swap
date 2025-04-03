/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:21:19 by toroman           #+#    #+#             */
/*   Updated: 2025/04/03 14:49:41 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node(t_node **node, int num)
{
	t_node	*new;
	t_node	*tmp;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->next = NULL;
	new->data = num;
	new->cheapest = 0;
	if (*node == NULL)
		*node = new;
	else
	{
		tmp = *node;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	init_node_a(t_node *stack_a, t_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}

void	init_node_b(t_node *stack_a, t_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}

void	free_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		arg[i] = NULL;
		i++;
	}
	free(arg);
	arg = NULL;
}
