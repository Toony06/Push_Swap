/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:11:38 by toroman           #+#    #+#             */
/*   Updated: 2025/03/07 17:31:46 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
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
	struct s_node	*next;
}	t_node;

char	*ft_strjoin1(char *s1, char *s2);
void	checkall(t_parse *parse, char **av);
void	checkint(char *str);
void	checkduplicate(t_parse *parse);
void	ft_error(char *str);
long	ft_atoi1(char *nptr);
void	init_node(t_node *node, t_parse *parse);
void	swap_node(t_node **stack);
void	print_stack(t_node *stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
t_node	*find_last_node(t_node **stack);
void	ra(t_node **stack_a);
void	rotate_reverse(t_node **stack);
void	rra(t_node **stack_a);
void	rrr(t_node **stack_a, t_node **stack_b);
void	push_instruction(t_node **dest, t_node **src);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
#endif
