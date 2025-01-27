NAME 				= 			push_swap

PRINTF				=			/includes/ft_printf/libftprintf.a

HEAD 				=			push_swap.h

OBJ_DIR				=			obj/

MAKEFLAG			+=			--no-print-directory

CC					=			cc

CFLAGS				=		-Wall -Werror -Wall -MMD -MP

SRCS             =        $(SRC_ACC)
#SRCS				=			$(addprefix $(SRC_DIR), $(SRC_ACC))

SRCS_DIR				=			srcs/

ALGO_DIR			=			algorithm/

OPE_DIR				=			operations/

PARSING_DIR			=			parsing/

SORT_DIR			=			sort/

STACK_DIR			=			stack/

UTILS_DIR			=			utils/


ALGO_SRCS			=			radix				\

OPE_SRCS			=			push				\
								reverse_rotate		\
								rotate				\
								swap

PARSING_SRCS		=			imput_parse			\
								imput_validate		\
								parsing_utils

SORT_SRCS			=			radix_sort			\
								sort_four_to_nine	\
								sort_stacks			\
								sort_three

STACK_SRCS			=			stack_init			\
								stack_utils

UTILS_SRCS			=			error_handling

SRC_ACC				+=			$(addprefix $(ALGO_DIR), $(addsuffix .c, $(ALGO_SRCS)))
SRC_ACC				+=			$(addprefix $(OPE_DIR), $(addsuffix .c, $(OPE_SRCS)))
SRC_ACC				+=			$(addprefix $(PARSING_DIR), $(addsuffix .c, $(PARSING_SRCS)))
SRC_ACC				+=			$(addprefix $(SORT_DIR), $(addsuffix .c, $(SORT_SRCS)))
SRC_ACC				+=			$(addprefix $(STACK_DIR), $(addsuffix .c, $(STACK_SRCS)))
SRC_ACC				+=			$(addprefix $(UTILS_DIR), $(addsuffix .c, $(UTILS_SRCS)))


#OBJ			=			$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
OBJ              =        $(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))

DEP			=			$(OBJ:.o=.d)

-include $(DEP)

.DEFAULT_GOAL	= all

all:					$(NAME)

$(NAME):				$(OBJ) $(PRINTF) Makefile
							echo "$(SRC)"
							$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
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