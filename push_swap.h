/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:11:38 by toroman           #+#    #+#             */
/*   Updated: 2025/03/04 17:13:52 by toroman          ###   ########.fr       */
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
#endif
