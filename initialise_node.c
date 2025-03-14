/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:21:19 by toroman           #+#    #+#             */
/*   Updated: 2025/03/13 21:35:56 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node(t_node **node, int num)
{
	t_node	*new;
	t_node	*tmp;
	//t_node	*stack_b = NULL;
	
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->next = NULL;
	new->data = num;
	if (*node == NULL)
		*node = new;
	else
	{
		tmp = *node;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
