/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:34:09 by toroman           #+#    #+#             */
/*   Updated: 2025/03/13 16:33:16 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_node *stack)
{
	if (!stack)
		return ;
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (true);
		stack = stack->next;
	}
	return (true);
}
