NAME			:=	philo

CC				:=	gcc

CFLAGS			:=	-g -pthread -Wall -Wextra -Werror

RM				:=	rm -rf

OBJS_DIR		:=	obj/

SRCS_DIR		:=	src/

SRCS			:=	main.c				\
					utils.c				\
					check_args.c		\
					init.c				\
					actions.c			\
					monitoring.c		\
					time.c				\
					actions_utils.c		\
					print_info.c		\
					destroy_and_free.c

OBJS			:=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

# COLORS ================================================================= #

RED		=	\033[0;91m
GREEN	=	\033[0;92m
YELLOW	=	\033[0;93m
WHITE	=	\033[0;97m

# ======================================================================== #

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "$(GREEN)Compiling:$(WHITE) $<"

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(YELLOW)- Program Name: $(WHITE)${NAME}"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)All object files removed.$(WHITE)"

fclean: clean
	@$(RM) $(NAME) $(OBJS_DIR)

re: fclean all

.PHONY: all clean fclean re

.SILENT:
