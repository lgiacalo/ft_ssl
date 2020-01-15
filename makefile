# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 19:28:04 by lgiacalo          #+#    #+#              #
#    Updated: 2019/03/22 20:18:14 by lgiacalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SSL		= ft_ssl

################################################################################

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror $(OPT) $(INCFLAG)
INCFLAG		= -Iinclude -Ilibft/include
OPT			=

COLOR		= \033[31m
FINCOLOR	= \033[0m

SPY			= @

################################################################################

SRC_PATH	= ./src/
INC_PATH	= ./include/

SRC_SSL		= main.c struct_ssl.c struct_sha.c\
				read_string.c read_file.c\
				parsing.c md5.c functions_md5.c\
				reverse.c math_utils.c\
				display.c print.c print_info.c\
				functions_sha32b.c sha256.c parsing_sha.c\
				

OBJ_SSL		= $(addprefix $(SRC_PATH), $(SRC_SSL:%.c=%.o))

INC_SSL		= ft_ssl.h ft_md5.h ft_sha.h

LIB		= libft/libft.a

################################################################################


ifeq ($(option), debug)
	OPT += -g
endif
ifeq ($(option), alloc)
	CFLAGS = -g -fsanitize=address $(INCFLAG) 
endif
ifeq ($(option), opti)
	OPT += -O3
endif
ifeq ($(option), dev)
	CFLAGS = -g $(INCFLAG)
endif

export OPT


################################################################################

all: $(SSL)

$(LIB):
	make -C $(dir $(LIB))

$(OBJ_SSL): $(addprefix $(INC_PATH), $(INC_SSL)) Makefile

$(SSL): $(LIB) $(OBJ_SSL)
	$(CC) $(CFLAGS) -o $@ $(OBJ_SSL) $(LIB)
	$(SPY)echo "$(COLOR)$(SSL)\t\t\t[OK]$(FINCOLOR)"


clean:
	make -C $(dir $(LIB)) fclean
	$(RM) $(OBJ_SSL)
	$(SPY)echo "$(COLOR)$(SSL)\t\t\tSuppression *.o$(FINCOLOR)"

fclean: clean
	$(RM) $(SSL)
	$(SPY)echo "$(COLOR)$(SSL)\t\t\tSuppression $(SSL)$(FINCOLOR)"

norme:
	$(SPY)echo "$(COLOR)\tNORMINETTE : $(SSL)\n$(FINCOLOR)"
	$(SPY)norminette $(SRC_PATH)/*.c
	$(SPY)norminette $(INC_PATH)/*.h

re: fclean all

.PHONY : all clean fclean re norme
