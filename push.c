/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:26:09 by toroman           #+#    #+#             */
/*   Updated: 2025/02/28 17:28:43 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	init_node(t_node *node, t_parse *parse)
{
	int	i;
	t_node	*new_node;

	new_node = node;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return;
	i = 0;
	while (parse->aatoi[i])
	{
		new_node->data = parse->aatoi[i];
		i++;
		new_node = new_node->next;
	}
}
