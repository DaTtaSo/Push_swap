NAME 		= 			push_swap

PRINTF=/includes/ft_printf/libftprintf.a

HEAD 		=			push_swap.h

OBJ_DIR		=			obj/

MAKEFLAGS	+= --no-print-directory

CC			=			cc

CFLAGS		=			-Wall -Werror -Wall -MMD -MP


SRCS	=			$(addprefix $(SRC_DIR), $(SRC_ACC))

SRC_DIR			=			srcs/

PARSING_DIR	=			parsing/
SORT_DIRECTORY		= sort/
OPE_DIRECTORY		= operations/

PARSING_SRC =			\
			testttttt \
SORT_SRC	= sort \

SRC_ACC			+= $(addprefix $(PARSING_DIR), $(addsuffix .c, $(PARSING_SRC)))
SRC_ACC			+=


OBJ			=			$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

DEP			=			$(OBJ:.o=.d)

-include $(DEP)

.DEFAULT_GOAL	= all

all:					$(NAME)

$(NAME):				$(OBJ) $(PRINTF) Makefile
							echo "$(SRC)"
							$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)%.o: $(SRCS_PATH)%.c
						@mkdir -p $(dir $@)
						$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF): FORCE
	$(MAKE) -C includes/ft_printf

clean:
						@rm -rf $(OBJ_DIR)
						@echo "Deleting $(OBJ_DIR)"


fclean:					clean
							$(MAKE) fclean -C includes/ft_printf
							@rm -rf $(NAME)
							@echo "Deleting $(NAME)"


re: 					fclean
						$(MAKE) all



FORCE:

#.SILENT:				clean

.PHONY: 				re all clean fclean FORCE