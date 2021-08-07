SRCS_S			= server.c server_utils.c
SRCS_C			= client.c
BONUS_SRCS_S	= server_bonus.c server_utils.c
BONUS_SRCS_C	= client_bonus.c client_utils.c
INCS_S			= server.h 
INCS_C			= client.h
BONUS_INCS_C	= client_bonus.h 
BONUS_INCS_S	= server_bonus.h
OBJS_S       	= $(SRCS_S:.c=.o)
OBJS_C       	= $(SRCS_C:.c=.o)
OBJS_BONUS_S	= $(BONUS_SRCS_S:.c=.o)
OBJS_BONUS_C	= $(BONUS_SRCS_C:.c=.o)
NAME			= server
CLI			= client
NAME_B			= server_bonus
CLI_B		= client_bonus
CFLAGS		= -Wall -Wextra -Werror
CC		= gcc
RM		= rm -f

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
$(NAME):	$(OBJS_S) $(OBJS_C)
		$(CC) $(CFLAGS) $(OBJS_S) -o $(NAME) -I $(INCS_S)
		$(CC) $(CFLAGS) $(OBJS_C) -o $(CLI) -I $(INCS_C)
all:	$(NAME)

$(NAME_B): $(OBJS_BONUS_S) $(OBJS_BONUS_C)
		$(CC) $(CFLAGS) $(OBJS_BONUS_S) -o $(NAME_B) -I $(BONUS_INCS_S)
		$(CC) $(CFLAGS) $(OBJS_BONUS_C) -o $(CLI_B) -I $(BONUS_INCS_C)
bonus:	$(NAME_B)

clean:
		$(RM) $(OBJS_S) $(OBJS_C) $(OBJS_BONUS_S) $(OBJS_BONUS_C)

fclean:		clean
		$(RM) $(NAME) $(NAME_B) $(CLI_B) $(CLI)

re:		fclean all

bonus: all

.PHONY: 	all clean fclean re .c.o bonus
