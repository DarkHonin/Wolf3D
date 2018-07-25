include ../gen.mk

NAME=libvect.a

main: start

make: $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "LIB MADE"