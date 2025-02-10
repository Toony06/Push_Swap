# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 11:34:23 by toroman           #+#    #+#              #
#    Updated: 2025/02/10 11:39:10 by toroman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c parsing.c
OBJS = ${SRCS:.c=.o}
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
LIBFT = ./utils
INCLUDES = -I/usr/include -Imlx -Iincludes

# Couleurs ANSI
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

# Barre de chargement compacte et colorée
define progress_bar
	@i=0; \
	while [ $$i -le 20 ]; do \
		printf "${BLUE}\r[${GREEN}%-20s${BLUE}]${YELLOW} %d%%${RESET}" "$$(printf '▓%.0s' $$(seq 1 $$i))" $$((i*5)); \
		sleep 0.1; \
		i=$$((i+1)); \
	done; \
	echo
endef

all : ${NAME}

${NAME}: ${OBJS}
	@echo "${BLUE}Compilation en cours...${RESET}"
	@$(progress_bar) & \
	PROGRESS_PID=$$!; \
	${MAKE} -C ./utils/ > /dev/null 2>&1; \
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ./utils/utils.a > /dev/null 2>&1; \
	kill $$PROGRESS_PID 2>/dev/null || true; \
	echo "${GREEN}\nCompilation terminée !${RESET}"

.c.o:
	@$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES) > /dev/null 2>&1

clean:
	@${MAKE} clean -C ./utils/ > /dev/null 2>&1
	@${RM} ${OBJS} > /dev/null 2>&1
	@echo "${YELLOW}Nettoyage des fichiers objets terminé.${RESET}"

fclean: clean
	@${RM} ${NAME} ./utils/utils.a > /dev/null 2>&1
	@echo "${RED}Nettoyage complet terminé.${RESET}"

re: fclean all

.PHONY: all clean fclean re
