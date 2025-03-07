/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:21:19 by toroman           #+#    #+#             */
/*   Updated: 2025/03/07 17:21:22 by toroman          ###   ########.fr       */
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
	i = 1;
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
	print_stack(node);
	rra(&node);
	print_stack(node);
}
