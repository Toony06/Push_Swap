/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:11:38 by toroman           #+#    #+#             */
/*   Updated: 2025/02/16 16:49:44 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "utils/header/libft.h"
# include "utils/header/ft_printf.h"

typedef struct s_parse
{
	char	**str;
	char	*tab;
	int		*aatoi;
}	t_parse;

char	*ft_strjoin1(char const *s1, char const *s2);
void	checkall(t_parse *parse, char **av);
void	checkint(char *str);
void	checkduplicate(t_parse *parse);
#endif
