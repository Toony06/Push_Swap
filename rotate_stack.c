/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:34:05 by toroman           #+#    #+#             */
/*   Updated: 2025/03/07 15:38:33 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_node **stack)
{
	t_node	*first_node;
	t_node	*last_node;

	first_node = *stack;
	last_node = find_last_node(stack);
	*stack = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
}

void	ra(t_node **stack_a)
{
	rotate_stack(stack_a);
	ft_printf("ra\n");
}

void	rb(t_node **stack_b)
{
	rotate_stack(stack_b);
	ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	ft_printf("rr\n");
}
