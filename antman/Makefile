##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## root Makefile
##

CC		=	gcc

NAME	=	antman

SRC		=	src/main.c \
			src/gestion_node.c \
			src/bit_shift.c \
			src/sort_my_tree.c \
			src/set_binary_tree.c \
			src/set_char.c \
			src/rev_bit.c \
			src/rev_bit_tool.c

OBJ		=	$(SRC:%.c=%.o)

CFLAGS	=	-I./include
LDFLAGS	=	-L./lib -lmy

all	:	make_lib $(NAME)

make_lib:
	make -C lib/my

$(NAME)	: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
	rm -rf $(OBJ)
	make clean -C lib/my

cclean	:
	rm $(NAME)

fclean	:
	make fclean -C lib/my
	rm -f $(NAME)

tclean	:
	make fclean -C tests

re	: fclean all

full	:
	make full -C lib/my

.PHONY	:	all tests fclean

debug: CFLAGS += -g
debug: re