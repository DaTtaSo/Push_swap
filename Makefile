NAME 				= 			push_swap

LIBFT				=			includes/libft/libft.a

INCLUDES = -I includes -I includes/libft

HEAD 				=			push_swap.h

OBJ_DIR				=			obj/

CC					=			cc

CFLAGS				=		-Wall -Werror -Wall -MMD -MP -g3

SRCS				=			$(addprefix $(SRCS_DIR), $(SRC_ACC))

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

UTILS_SRCS			=			error_handling		\
								error_utils

MAIN_SRCS			=			main

SRC_ACC				+=			$(addprefix $(ALGO_DIR), $(addsuffix .c, $(ALGO_SRCS)))
SRC_ACC				+=			$(addprefix $(OPE_DIR), $(addsuffix .c, $(OPE_SRCS)))
SRC_ACC				+=			$(addprefix $(PARSING_DIR), $(addsuffix .c, $(PARSING_SRCS)))
SRC_ACC				+=			$(addprefix $(SORT_DIR), $(addsuffix .c, $(SORT_SRCS)))
SRC_ACC				+=			$(addprefix $(STACK_DIR), $(addsuffix .c, $(STACK_SRCS)))
SRC_ACC				+=			$(addprefix $(UTILS_DIR), $(addsuffix .c, $(UTILS_SRCS)))
SRC_ACC				+=			$(addsuffix .c, $(MAIN_SRCS))


OBJ			=			$(patsubst $(SRCS_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

DEP			=			$(patsubst $(SRCS_DIR)%.c,$(OBJ_DIR)%.d,$(SRCS))

-include $(DEP)

all:					$(NAME)

$(NAME):				$(OBJ) $(LIBFT)
							echo "$(SRC)"
							$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
						@mkdir -p $(dir $@)
						$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT): FORCE
	$(MAKE) -C includes/libft

clean:
						@rm -rf $(OBJ_DIR)
						@echo "Deleting $(OBJ_DIR)"


fclean:					clean
							@rm -rf $(NAME)
							@echo "Deleting $(NAME)"


re: 					fclean
						$(MAKE) all

FORCE:

.PHONY: 				re all clean fclean Makefile FORCE