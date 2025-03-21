/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:30:26 by toroman           #+#    #+#             */
/*   Updated: 2025/03/22 00:15:38 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node_b(t_node *stack_a, t_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}

t_node	*find_min(t_node *stack)
{
	long	min;
	t_node	*mine_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if ((stack)->data < min)
		{
			min = (stack)->data;
			mine_node = stack;
		}
		stack = (stack)->next;
	}
	return (mine_node);
}

void	rev_rotate_both(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node
		&& *stack_a != cheapest_node)
		rrr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

t_node	*get_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
