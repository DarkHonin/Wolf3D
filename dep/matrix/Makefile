LIBFT=libft
INCLUDES= -I "$(LIBFT)"
LIBS=-lft -L "$(LIBFT)"

OBJ=matrix.o matrix_err.o matrix_math.o

NAME=libmatrix.a

make: $(DEPS) $(OBJ)
	@echo $(LIBFT)
	@gcc testmain.c $(OBJ) $(INCLUDES) $(LIBS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "LIB MADE"

$(OBJ):
	gcc $*.c -c $(INCLUDES)

$(DEPS):
	make -C $(LIBFT) $(CMD)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean make