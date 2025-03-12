/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:21:19 by toroman           #+#    #+#             */
/*   Updated: 2025/03/12 14:41:37 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	init_node(t_node *node, t_parse *parse)
{
	int		i;
	t_node	*new_node;
	t_node	*temp;
	t_node	*stack_b = NULL;

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
	printf("stack a before push: \n");
	print_stack(node);
	printf("stack b before push: \n");
	print_stack(stack_b);
	pa(&stack_b, &node);
	printf("stack a after push: \n");
	print_stack(node);
	printf("stack b after push: \n");
	print_stack(stack_b);
}
