/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:11:38 by toroman           #+#    #+#             */
/*   Updated: 2025/02/27 18:15:21 by tony             ###   ########.fr       */
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
}	t_parse;

typedef struct s_node
{
	int data;
	struct s_node *next;
}	t_node;

char	*ft_strjoin1(char *s1, char *s2);
void	checkall(t_parse *parse, char **av);
void	checkint(char *str, t_parse *parse);
void	checkduplicate(t_parse *parse);
void	ft_error(char *str, t_parse *parse);
long	ft_atoi1(char *nptr, t_parse *parse);
void	init_node(int value, t_node **stack, t_parse *parse);
void	ft_free(char **tab);
#endif
