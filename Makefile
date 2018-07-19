NAME=Wolf3D
LIBS=-L lib
INCLUDE=-I lib/includes

FILES:=$(basename $(shell ls src))
OBJ:=$(foreach obj,$(FILES),$(addprefix obj/,$(addsuffix .o,$(obj))))

GC=gcc

setup_win:
	make -C dep win

setup_mac:
	make -C dep mac

win32: $(OBJ)
	$(GC) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBS) -lmingw32 -lSDL2main -lSDL2 -mwindows -lft

mac: $(OBJ)
	$(GC) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBS) -framework OpenGL -framework AppKit -lSDL2main -lSDL2 -lft 

$(OBJ):
	mkdir -p obj
	$(GC) src/$(notdir $*).c -o $@ $(INCLUDE) -c 

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

re: clean $(NAME)