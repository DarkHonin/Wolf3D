NAME=Wolf3D
LIBS=-L lib # -L /goinfre/wgourley/.brew/Cellar/sdl2/2.0.8/lib
INCLUDE=-I lib/includes #-I /goinfre/wgourley/.brew/include/

FILES:=$(basename $(shell ls src))
OBJ:=$(foreach obj,$(FILES),$(addprefix obj/,$(addsuffix .o,$(obj))))

GC=gcc

win: $(OBJ)
	$(GC) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBS) -lmingw32 -lSDL2main -lSDL2 -mwindows -lvect -lft 

mac: $(OBJ)
	@echo \e[32mMaking
	$(GC) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBS) -framework OpenGl -lSDL2 -lft -framework AppKit -framework Cocoa

$(OBJ):
	mkdir -p obj
	@echo -e "\e[32mMaking"
	$(GC) src/$(notdir $*).c -o $@ $(INCLUDE) -c 

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

rebuild: clean
	make -C dep CMD=re
	$(MAKE) re

re: clean
	$(MAKE) $(CMD)