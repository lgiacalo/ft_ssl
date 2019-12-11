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

SRC_SSL		= main.c struct_ssl.c\
				parsing.c parsing_option_s.c parsing_args.c\
				print.c print_info.c

OBJ_SSL		= $(addprefix $(SRC_PATH), $(SRC_SSL:%.c=%.o))

INC_SSL		= ft_ssl.h

LIB		= libft/libft.a

################################################################################


ifeq ($(option), debug)
	OPT += -g
endif
ifeq ($(option), alloc)
	OPT += -g -fsanitize=address
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
