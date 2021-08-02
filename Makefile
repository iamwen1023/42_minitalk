SRCS_S		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
            ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_C		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
BONUS_SRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c
INCS		= libft.h
OBJS        = $(SRCS:.c=.o)
OBJS_BONUS	= $(BONUS_SRCS:.c=.o)
CFLAGS		= -Wall -Wextra -Werror
NAME		= libft.a
CC		= cc -c
RM		= rm -f
AR		= ar rcs 

$(NAME):	$(OBJS) $(INCS)
			$(AR) $(NAME) $(OBJS)
		
all:	$(NAME)

bonus:	$(OBJS_BONUS) $(OBJS) $(INCS)
		@touch bonus
		$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)

%.o: %.c
		$(CC) -o $@ $< $(CFLAGS)
so:
		$(CC) -fPIC $(CFLAGS) $(SRCS)
		gcc -shared -o libft.so $(OBJS)
cleanso:
		rm *.o
		rm -f libft.so
clean:
		$(RM) $(OBJS) bonus

fclean:		clean
		$(RM) $(NAME)

re:		fclean all


.PHONY: 	all clean fclean re .c.o cleanso so