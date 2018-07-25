LIB_CFG=$(realpath ../libs.mk)
include ../gen.mk

NAME=libmatrix.a

main: start

make: $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "LIB MADE"