#--STANDARD--
NAME	= philo
CFLAGS	= -Wall -Wextra -Werror -g3
CFLAGS = -g
VPATH	= $(addprefix $(SRC_D)/, $(DIRS))

#--DIRS--
SRC_D		= ./src/
DIRS		= . actions init time main utils Error testes
OBJ_D		= ./objects
INCLUDE_D	= ./include

#--FILES--
SRC		= $(ACT) $(INIT) $(TIME) $(MAIN) $(UTIL) $(ERROR) $(TESTES)

ACT		= routine.c actions.c
INIT	= init.c create.c line.c
TIME	= time.c
MAIN	= philo.c manager.c
UTIL	= utils.c utils2.c
ERROR	= error.c
TESTES	= testes.c

HEADERS	= ./include/philo.h
INCLUDE	= -I $(INCLUDE_D) 

#--OBJECTS--
OBJ		= $(SRC:%.c=$(OBJ_D)/%.o)

#--COLORS--
WHITE	=	\e[00m
GREEN	=	\e[32m
RED		=	\e[91m
YELLOW	=	\e[033m
BLUE	=	\e[34m

NUMBER_OF_SRC_FILES	=	$(words $(SRC))
PROGRESS			=	0

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_D) $(HEADERS)
	@echo "$(BLUE)Compiling $(WHITE)Philosophers"
	@cc $(CFLAGS) $(INCLUDE) $(OBJ) -lreadline -lpthread -o $@
	@echo "$(GREEN)Compiled $(WHITE)Philosophers"

$(OBJ_D)/%.o: %.c Makefile | $(OBJ_D)
	@cc -c $(CFLAGS) $< -o $@
	@echo -n "$(YELLOW)Compiling $(WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_OF_SRC_FILES)))%\r"
	$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))

$(OBJ_D):
	@mkdir -p $@

clean:
	@echo "$(BLUE)Removing $(WHITE)Philosophers objects"
	@rm -rf $(OBJ_D)

fclean: clean
	@echo "$(BLUE)Removing $(WHITE)$(NAME)"
	@rm -rf $(NAME)

re: fclean all