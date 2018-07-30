
LIB_CFG=dep/libs.mk

NAME=Wolf3D.a
include dep/gen.mk
DD = $(shell echo $(WORKING_DIR))
export NAME

make: $(OBJS)
	gcc -o $(NAME) $(OBJS) $(INCLUDE) $(addprefix -L,$(LIBRAIRIES)) -I$(INCLUDE_DIR) $(LINKS) -framework OpenGl -framework Appkit

build:
	make -C dep

rebuild:
	make -C dep/$(LIB) fclean
	$(MAKE) build