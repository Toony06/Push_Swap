/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:22:30 by toroman           #+#    #+#             */
/*   Updated: 2025/03/24 18:37:29 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_parse	parse;
	t_node	*node = NULL;
	t_node	*node1 = NULL;
	int		i;
	long	num;

	i = 1;
	if (ac < 2 || (!av[1][0] && ac == 2))
		ft_error("Error");
	checkall(&parse, av);
	while (av[i])
	{
		num = ft_atoi1(av[i]);
		init_node(&node, (int)num);
		i++;
	}
	main2(node, node1);
	// printf("stack a before push:\n");
	// print_stack(node);
	// printf("stack b before push:\n");
	// print_stack(node1);
	// pb(&node, &node1);
	// printf("stack a after push:\n");
	// print_stack(node);
	// printf("stack b before push:\n");
	// print_stack(node1);
}

void	main2(t_node *node, t_node *node1)
{ 
	if (!stack_sorted(node))
	{
		if (stack_len(node) == 2)
			sa(&node);
		else if (stack_len(node) == 3)
			sort_three(&node);
		else
			sort_stacks(&node, &node1);
	}
	free_stack(node);
}
