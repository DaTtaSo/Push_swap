NAME 		= 			push_swap

HEAD 		=			push_swap.h

OBJ_DIR		=			obj/

CC			=			cc

CFLAGS		=			-Wall -Werror -Wall -MMD -MP

AR			=			ar -rcs

SRC			=			push.c


OBJ			=			$(SRC:%.c=$(OBJ_DIR)%.o)
DEP			=			$(SRC:%.c=$(OBJ_DIR)%.d)

$(OBJ_DIR)%.o: %.c $(HEAD) Makefile | $(OBJ_DIR)
						$(CC) $(CFLAGS) -c $< -o $@

all:					$(NAME)

$(NAME):				$(OBJ)
							$(AR) $@ $?

$(OBJ_DIR):
						@mkdir -p $(OBJ_DIR)
.PHONY: 				all

clean:
						@rm -rf $(OBJ) $(OBJ_DIR)
						@echo "Deleting $(OBJ_DIR)"
.PHONY: 				clean

fclean:					clean
							@rm -rf $(NAME)
							@echo "Deleting $(NAME)"
.PHONY: 				fclean

re: 					fclean
						$(MAKE) all

.PHONY: 				re
#.SILENT:				clean
-include $(DEP)
