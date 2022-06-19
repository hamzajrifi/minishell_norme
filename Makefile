NAME = mini.a

CC = gcc

FLAG = -Wall -Wextra -Werror

HDR = 	header/minishell.h \
		header/utiles_functions.h

C_FILES =	main.c\
			functions/utiles_functions.c\
			exec/exec_cmd.c\
			exec/redirections.c\
			exec/pipes.c\
			built_func/cd.c\
			built_func/echo.c\
			built_func/env.c\
			built_func/exit.c\
			built_func/export.c\
			built_func/pwd.c\
			built_func/unset.c\
			built_func/utils_exp.c\
			parsing/parser.c\
			parsing/parser_second.c\
			utils/ft_split.c\
			utils/ft_strjoin.c\
			utils/ft_substr.c\
			utils/all_func.c\
			utils/ft_strcmp.c\
			utils/ft_itoa.c\
			utils/ft_calloc.c\
			exec/ft_getenv.c\
			exec/sec_heredoc.c\
			lexer/mini.c\
			functions/ft_error.c\
			get/get_next_line.c\
			exec/exit_status.c\
			ft_free/ft_free_list.c\
			lexer/lexer_action.c\
			lexer/lexer.c\
			lexer/token.c

OBJ = $(C_FILES:.c=.o)
# main.o\
# 		functions/utiles_functions.o\
# 		mini.o


all : $(NAME)

$(NAME) : $(HDR) $(OBJ)
			$(CC)  -c $(C_FILES)
			ar -rc $(NAME) $(OBJ)
			$(CC)  -o minishell main.c -lreadline $(NAME)

clean :	
		rm -f *.o functions/*.o
		rm -f *.o ft_free/*.o
		rm -f *.o built_func/*.o
		rm -f *.o exec/*.o
		rm -f *.o utils/*.o
		rm -f *.o parsing/*.o
		rm -f *.o lexer/*.o
		rm -f $(NAME)
fclean : clean
		rm -f minishell
re : fclean all