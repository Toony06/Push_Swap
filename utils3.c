/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:17:15 by toroman           #+#    #+#             */
/*   Updated: 2025/03/21 15:52:42 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}
void	set_target_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_b;
	t_node	*target_node;
	long	best_match_index;

	while(stack_a)
	{
		best_match_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->data < stack_a->data
				&& current_b->data > best_match_index)
			{
				best_match_index = current_b->data;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
		stack_a->target_node = find_max(&stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;

	}
}

void	cost_analysis_a(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - (stack_a->index);
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += len_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

void	set_cheapest(t_node *stack)
{
	long		cheapest_value;
	t_node		*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	move_a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
			&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target_node, 'b');
	pb(stack_b, stack_a);
}
