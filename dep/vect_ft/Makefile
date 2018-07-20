LIBFT:=$(realpath ../libft)
LIBTEST=$(realpath ../Testing)
LIBS:= '$(LIBFT)' '$(LIBTEST)'
LIB:=-L'$(LIBFT)' -L'$(LIBTEST)' -L. -ltest -lvect -lft
INCLUDES:= -I'$(LIBFT)' -I'$(LIBTEST)' -I.
NAME=libvect.a

OBJS:=vector.o vec_utils.o vect_info.o

$(NAME): make

$(OBJS):
	@echo "Making $*.o"
	@gcc -c $*.c -o $@ $(INCLUDES) -g

clean:
	@rm -rf $(OBJS)
	@echo ".o's removed"

fclean: clean
	@rm $(NAME)
	@echo "Librairy removed"

re: fclean make

make: $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "LIB MADE"

make_test: make_libs make
	@gcc $(MAIN) $(OBJS) $(INCLUDES) $(LIB)

make_libs:
	@echo "Libft: $(LIBFT)"
	@for i in $(LIBS); do \
		make -C "$$i" all LIBFT='$(LIBFT)'; \
	done

make_re:
	@for i in $(LIBS); do \
		make -C "$$i" re LIBFT="$(LIBFT)"; \
	done