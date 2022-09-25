NAME = philo
CC = cc
SRC = check_utils.c init_args.c thread_utils.c create_list.c philo.c tools.c
FLAGS = -Wall -Wextra -Werror
all : philo

$(NAME): $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@tput setaf 2; echo "PHILOSOPHERS ARE READY"

clean :
	@rm -f philo
	@tput setaf 1; echo "CLEAN COMPLETED"

fclean : clean

re: fclean all