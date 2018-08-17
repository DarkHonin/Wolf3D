LIBDIR=dep
LIB_CFG=dep/libs.mk
NAME=Wolf3D.bin
include dep/gen.mk
export NAME

make: $(OBJS) build
	gcc -o $(NAME) $(OBJS) $(INCLUDE) $(addprefix -L,$(LIBRAIRIES)) -I$(INCLUDE_DIR) $(LINKS) -framework OpenGl -framework Appkit -lmlx

build:
	make -C dep

flash: fclean
	make -C dep/$(LIB) fclean

rebuild:
	make -C dep/$(LIB) fclean
	$(MAKE) build