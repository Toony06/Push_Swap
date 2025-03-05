/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:09:15 by toroman           #+#    #+#             */
/*   Updated: 2025/03/05 17:22:05 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_node(t_node **stack)
{
	t_node	*temp;

	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = *stack;
	*stack = temp;
}

void	sa(t_node **stack_a)
{
	swap_node(stack_a);
	ft_printf("sa\n");
}


void	sb(t_node **stack_b)
{
	swap_node(stack_b);
	ft_printf("sb\n");
}


void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_node(stack_a);
	swap_node(stack_b);
	ft_printf("ss\n");
}
