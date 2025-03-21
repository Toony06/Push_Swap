/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:03:03 by toroman           #+#    #+#             */
/*   Updated: 2025/03/21 16:50:44 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_to_a(t_node **stack_a, t_node **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b);
}

void	min_on_top(t_node **stack)
{
	while ((*stack)->data != find_min(stack)->data)
	{
		if (find_min(stack)->above_median)
			ra(stack);
		else
			rra(stack);
	}
}

void	rotate_both(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

void	prep_for_push(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	set_target_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_a;
	t_node	*target_node;
	long	best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->data > stack_b->data
				&& current_a->data < best_match_index)
			{
				best_match_index = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			stack_b->target_node = find_min(&stack_a);
		else
				stack_b->target_node = target_node;
			stack_b = stack_b->next;
	}
}
