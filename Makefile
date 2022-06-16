##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

all :
	make -C antman/
	make -C giantman/

clean:
	make clean -C antman
	make clean -C giantman

fclean:	clean
	make fclean -C antman
	make fclean -C giantman

re: fclean all

debug:
	make -C antman/ debug
	make -C giantman/ debug

.PHONY: all clean fclean re debug
