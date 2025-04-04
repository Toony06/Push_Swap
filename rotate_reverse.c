/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:25:53 by toroman           #+#    #+#             */
/*   Updated: 2025/04/03 10:53:43 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse(t_node **stack)
{
	t_node	*last_node;
	t_node	*before_last;

	if (!(*stack))
		return ;
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	before_last = *stack;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last_node->next = *stack;
	before_last->next = NULL;
	*stack = last_node;
}

void	rra(t_node **stack_a)
{
	rotate_reverse(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	rotate_reverse(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rotate_reverse(stack_a);
	rotate_reverse(stack_b);
	ft_printf("rrr\n");
}

void	rev_rotate_both(t_node **stack_a, t_node **stack_b,
			t_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node
		&& *stack_a != cheapest_node)
		rrr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}
