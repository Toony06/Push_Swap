/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:39:24 by toroman           #+#    #+#             */
/*   Updated: 2025/04/03 10:54:55 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_three(t_node **stack)
{
	t_node	*biggest_node;

	biggest_node = find_max(stack);
	if (biggest_node == *stack)
		ra(stack);
	else if ((*stack)->next == biggest_node)
		rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}

int	stack_len(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_node	*find_max(t_node **stack)
{
	t_node	*current;
	t_node	*biggest;

	current = *stack;
	biggest = *stack;
	if (*stack == NULL)
		return (NULL);
	while (current)
	{
		if (biggest->data < current->data)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

t_node	*find_last_node(t_node **stack)
{
	if (*stack == NULL)
		return (NULL);
	while ((*stack)->next)
		*stack = (*stack)->next;
	return (*stack);
}
