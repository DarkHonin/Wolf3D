NAME=Wolf3D
LIBS=-L lib -L lib/SDL2/
INCLUDE=-I lib/includes

FILES:=$(basename $(shell ls src))
OBJ:=$(foreach obj,$(FILES),$(addprefix obj/,$(addsuffix .o,$(obj))))

GC=gcc

$(NAME): $(OBJ)
	@echo $(FILES)
	$(GC) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBS) -lmingw32 -lSDL2main -lSDL2  -lft

setup_win:
	make -C dep win

win32: $(OBJ)
	$(GC) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBS) -lmingw32 -lSDL2main -lSDL2 -mwindows -lft

$(OBJ):
	mkdir -p obj
	$(GC) src/$(notdir $*).c -o $@ $(INCLUDE) -c 

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

re: clean $(NAME)