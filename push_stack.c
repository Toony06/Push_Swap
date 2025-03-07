/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:22:41 by toroman           #+#    #+#             */
/*   Updated: 2025/03/07 17:31:12 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_instruction(t_node **dest, t_node **src)
{
	t_node *node;

	if (!*src)
		return;
	node = *src;
	*src = (*src)->next;
	node->next = *dest;
	*dest = node;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push_instruction(*stack_a, *stack_b);
	ft_printf("pa\n");
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push_instruction(*stack_b, *stack_a);
	ft_printf("pb\n");
}
