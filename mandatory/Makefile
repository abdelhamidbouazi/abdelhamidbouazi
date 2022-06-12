# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouazi <abouazi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 05:50:19 by abouazi           #+#    #+#              #
#    Updated: 2022/06/12 18:11:43 by abouazi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MANDATORY = philo
NAME_BONUS = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_MANDATORY = philo.c parsing.c initialize.c inv_philos.c utils.c \
				../mandatory/ft_atoi.c

SRC_BONUS = ../bonus/philo_bonus.c \
			../tools/ft_isnumber.c \
			../tools/ft_strlen.c \
			../tools/ft_strcmp.c \
			../tools/ft_atoi.c \
			../tools/philos_states_bonus.c \
			../tools/utils_bonus.c \

OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

%.o: %.c philo.h
	CC $(CFLAGS) -c $< -o $@

$(NAME_MANDATORY): $(OBJ_MANDATORY)
	$(CC) $(OBJ_MANDATORY) -o $(NAME_MANDATORY)
	
$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -o $(NAME_BONUS)

all : $(NAME_MANDATORY)

bonus : $(NAME_BONUS)

clean :
	$(RM) $(OBJ_MANDATORY) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME_MANDATORY) $(NAME_BONUS)

re: fclean all