include ../gen.mk

NAME=libgnl.a

main: start

make: $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "LIB MADE"