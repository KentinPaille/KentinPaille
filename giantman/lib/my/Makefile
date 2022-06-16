##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

CC = gcc

CFLAGS =  -Wall -Wextra -Wshadow

SRC	=  	my_getnbr.c \
		my_put_nbr.c \
		my_putchar.c \
		my_putstr.c \
		my_revstr.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_strlen.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strstr.c \
		my_strupcase.c \
		my_compute_power_rec.c \
		my_compute_square_root.c \
		my_find_prime_sup.c \
		my_is_prime.c \
		my_isneg.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_strcapitalize.c \
		my_str_isupper.c \
		my_strlowcase.c \
		my_strcat.c \
		my_strncat.c \
		my_swap.c \
		my_show_word_array.c \
		my_printf.c \
		my_printf_2.c \
		my_printf_3.c \
		my_put_spe_nb.c

NAME = libmy.a

OBJ = $(SRC:.c=.o)

all	: $(NAME)

$(NAME)	: 	$(OBJ)
	ar rc $(NAME) *.o
	cp libmy.a ../
	mkdir -p ../../include
	cp my.h ../../include

clean	:
	$(RM) $(OBJ)

fclean	: 	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re	: fclean all
