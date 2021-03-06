NAME		= libftprintf.a

SRCS		= libpf/ft_parser.c libpf/ft_parser_auxiliary.c \
            libpf/ft_conversion_c.c libpf/ft_conversion_d.c \
            libpf/ft_conversion_p.c libpf/ft_conversion_s.c \
            libpf/ft_conversion_perc.c \
            ft_printf.c libft/ft_strlen.c libft/ft_putchar_fd.c \
            libft/ft_putstr_fd.c libft/ft_isdigit.c \
            libft/ft_putnbr_fd.c libft/ft_putnbr_with_base_fd.c \
            libpf/ft_abs.c libpf/ft_count_signs_in_number.c \
            libpf/ft_conversion_d_auxiliary.c

LIB			= ft_printf.h

OBJS		= ${SRCS:.c=.o}

.c.o:		${LIB}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

CC			= gcc

AR			= ar rc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

$(NAME):	${OBJS} ${LIB}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:	
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re so bonus