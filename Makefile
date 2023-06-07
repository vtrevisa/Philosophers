#--STANDARTD--
NAME	= philisophers
#CFLAGS	= -Wall -Wextra -Werror -g3
#SRCD	= ./src/
OBJD	= ./objects
#HEADER	= ./include/philosophers.h

#--MANDATORY--
SRC		= philo.c
OBJ		= $(addprefix $(OBJD)/, $(SRC:.c=.o))

#LIBFT
LIBFT	=$(addprefix $(LPATH)/, libft.a)
LPATH	=./Libft

#TEST
#TC		=thread_test.c
#TC		=deadlock_test.c
TC		=timestamp_test.c

all: $(NAME)
	./$(NAME)

$(NAME): $(LIBFT) $(OBJ) #$(HEADER)
	cc $(OBJ) $(LIBFT) $(CFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LPATH)

$(OBJD)/%.o: $(SRC)
	mkdir -p $(OBJD)
	cc -c $< -o $@
test:	$(LIBFT)
	gcc $(TC) $(LIBFT)
	./a.out
clean:
	rm -rf $(OBJD)

fclean: clean
	rm -rf $(NAME)

re: fclean all