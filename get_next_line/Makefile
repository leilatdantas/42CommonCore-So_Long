# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 12:44:40 by lebarbos          #+#    #+#              #
#    Updated: 2023/08/15 13:16:10 by lebarbos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COMMANDS
ifeq ($(UNAME), Darwin) # iMac / iOS
	CC = cc
else ifeq ($(UNAME), FreeBSD) # FreeBSD
	CC = clang
else #Linux and others...
	CC = cc
endif
AR = ar rcs
RM = rm -rf 

#FLAGS
CFLAGS = -Werror -Wextra -Wall 

#INCLUDE
DEPS = ../include 

#FILES
TARGET = get_next_line.o get_next_line_utils.o 
BONUS_TARGET = get_next_line_bonus.o get_next_line_utils_bonus.o 
NAME = libgnl.a 

#/////////////////////////////////////////////////////////////////

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)


all: $(NAME)

$(NAME): $(TARGET)
		$(AR) $(NAME) $^

bonus: $(TARGET) $(BONUS_TARGET)
		$(AR) $(NAME) $^

 clean: 
		$(RM) $(TARGET) $(BONUS_TARGET)

 fclean: clean
		$(RM) $(NAME) $(BONUS_TARGET)

re: fclean all 