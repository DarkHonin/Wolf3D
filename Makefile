NAME=Wolf3D
LIBS=-L lib
INCLUDE=-I lib/includes

FILES:=$(basename $(shell ls src))
OBJ:=$(foreach obj,$(FILES),$(addprefix obj/,$(addsuffix .o,$(obj))))

GC=gcc

$(NAME): $(OBJ)
	@echo $(FILES)
	$(GC) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit

$(OBJ):
	$(GC) src/$(notdir $*).c -o $@ $(INCLUDE) -c

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

re: clean $(NAME)