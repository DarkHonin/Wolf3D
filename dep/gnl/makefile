make:
	gcc -c get_next_line.c -Wextra -Wall -Werror -I $(LIBFT)
	@ar rc libgnl.a get_next_line.o
	@ranlib libgnl.a
	@echo "LIB MADE"

re:
	rm get_next_line.o
	rm libgnl.a
	$(MAKE)

	

