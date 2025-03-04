/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:26:09 by toroman           #+#    #+#             */
/*   Updated: 2025/03/04 17:13:34 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node(t_node *node, t_parse *parse)
{
	int		i;
	t_node	*new_node;
	t_node	*temp;

	node->data = parse->aatoi[0];
	node->next = NULL;
	temp = node;
	i = 0;
	while (parse->aatoi[i])
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return ;
		new_node->data = parse->aatoi[i];
		new_node->next = NULL;
		temp->next = new_node;
		temp = new_node;
		i++;
	}
}

void	swap_node(t_node **stack)
{
	t_node	*temp;

	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = *stack;
	*stack = temp;
	ft_printf("%d", stack)
}
