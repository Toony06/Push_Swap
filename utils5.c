/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:30:26 by toroman           #+#    #+#             */
/*   Updated: 2025/03/21 16:41:59 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node_b(t_node *stack_a, t_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}

t_node	*find_min(t_node **stack)
{
	t_node *current;
	t_node *min;

	current = *stack;
	min = *stack;
	if (*stack == NULL)
		return (NULL);
	while (current)
	{
		if (min->data > current->data)
			min = current;
		current = current->next;
	}
	return (min);
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
