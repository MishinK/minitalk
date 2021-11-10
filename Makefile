# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 20:10:48 by abarthel          #+#    #+#              #
#    Updated: 2019/02/03 21:40:59 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra -I .

SERVER = server
SERVER_SRCS = server.o send_message.o utility.o ft_itoa.o ft_atoi.o

CLIENT = client
CLIENT_SRCS = client.o send_message.o utility.o ft_itoa.o ft_atoi.o

SERVER_BONUS = server_bonus
SERVER_SRCS_BONUS = server_bonus.o send_message_bonus.o utility.o ft_itoa.o ft_atoi.o

CLIENT_BONUS = client_bonus
CLIENT_SRCS_BONUS = client_bonus.o send_message_bonus.o utility.o ft_itoa.o ft_atoi.o


all : $(SERVER) $(CLIENT)

bonus: fclean $(SERVER_BONUS) $(CLIENT_BONUS)

$(CLIENT) : $(CLIENT_SRCS)
	@$(CC) $(CLIENT_SRCS) -o $(CLIENT)
	@printf "\e[32m$@ built\e[0m\n"

$(SERVER) : $(SERVER_SRCS)
	@$(CC) $(SERVER_SRCS) -o $(SERVER)
	@printf "\e[32m$@ built\e[0m\n"


$(CLIENT_BONUS) : $(CLIENT_SRCS_BONUS)
	@$(CC) $(CLIENT_SRCS_BONUS) -o $(CLIENT_BONUS)
	@printf "\e[32m$@ built\e[0m\n"

$(SERVER_BONUS) : $(SERVER_SRCS_BONUS)
	@$(CC) $(SERVER_SRCS_BONUS) -o $(SERVER_BONUS)
	@printf "\e[32m$@ built\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c

clean :
	@rm -f $(SERVER_SRCS) $(CLIENT_SRCS) $(SERVER_SRCS_BONUS) $(CLIENT_SRCS_BONUS) 
	@printf "\e[31mclean done\e[0m\n"

fclean : clean
	@rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS) 
	@printf "\e[31mfclean done\e[0m\n"

re : fclean all

.PHONY: all clean fclean re
