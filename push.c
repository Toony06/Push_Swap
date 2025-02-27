/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:26:09 by toroman           #+#    #+#             */
/*   Updated: 2025/02/27 18:15:06 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	init_node(int value, t_node **stack, t_parse *parse)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return;
	new_node->data = value;
	new_node->next = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		t_node *temp;

		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
	free(parse->aatoi);
}
