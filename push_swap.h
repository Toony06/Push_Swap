/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:11:38 by toroman           #+#    #+#             */
/*   Updated: 2025/04/03 11:03:49 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>
# include "utils/header/libft.h"
# include "utils/header/ft_printf.h"

typedef struct s_parse
{
	char	**str;
	char	*tab;
	int		*aatoi;
	int		num;
}	t_parse;

typedef struct s_node
{
	int				data;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
}	t_node;

char	*ft_strjoin1(char *s1, char *s2);
void	checkall(t_parse *parse, char **av);
void	checkint(char *str);
void	checkduplicate(t_parse *parse);
void	ft_error(char *str);
long	ft_atoi1(char *nptr);
void	init_node(t_node **node, int num);
void	swap_node(t_node **stack);
void	print_stack(t_node *stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
t_node	*find_last_node(t_node **stack);
void	ra(t_node **stack_a);
void	rotate_reverse(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	rotate_stack(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	push_instruction(t_node **dest, t_node **src);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
bool	stack_sorted(t_node *stack);
void	free_arg(char **arg);
int		stack_len(t_node *stack);
t_node	*find_max(t_node **stack);
void	free_stack(t_node *stack);
void	sort_three(t_node **stack);
void	sort_stacks(t_node **stack_a, t_node **stack_b);
void	init_node_a(t_node *stack_a, t_node *stack_b);
void	current_index(t_node *stack);
void	cost_analysis_a(t_node *stack_a, t_node *stack_b);
void	set_cheapest(t_node *stack);
t_node	*get_cheapest(t_node *stack);
void	move_a_to_b(t_node **stack_a, t_node **stack_b);
void	move_b_to_a(t_node **stack_a, t_node **stack_b);
void	min_on_top(t_node **stack);
void	rev_rotate_both(t_node **stack_a, t_node **stack_b,
			t_node *cheapest_node);
void	rotate_both(t_node **stack_a, t_node **stack_b, t_node *cheapest_node);
void	prep_for_push(t_node **stack, t_node *top_node, char stack_name);
void	set_target_b(t_node *stack_a, t_node *stack_b);
void	set_target_a(t_node *stack_a, t_node *stack_b);
void	init_node_b(t_node *stack_a, t_node *stack_b);
t_node	*find_min(t_node *stack);
void	main2(t_node *node, t_node *node1);
#endif
