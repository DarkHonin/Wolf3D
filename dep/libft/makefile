LIB_CFG=$(realpath ../libs.mk)
include ../gen.mk

NAME=libft.a
export NAME
make: $(OBJS)

	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "LIB MADE"