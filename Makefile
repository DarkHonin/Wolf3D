NAME=Wolf3D
LIBS=-L lib  -L /goinfre/wgourley/.brew/Cellar/sdl2/2.0.8/lib
INCLUDE=-I lib/includes -I /goinfre/wgourley/.brew/include/

FILES:=$(basename $(shell find src/ -type f))
OBJ:=$(foreach obj,$(notdir $(FILES)),$(addprefix obj/,$(addsuffix .o,$(obj))))

GC=gcc

make:
	@for i in $(FILES); do \
		echo "Discovered: $$i"; \
	done
	$(MAKE) win

win: $(OBJ)
	$(GC) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBS) -lmingw32 -lSDL2main -lSDL2 -mwindows -lvect -lmatrix -lft

mac: $(OBJ)
	$(GC) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBS) -framework OpenGl -lSDL2 -lft -lvect -framework AppKit -framework Cocoa

$(OBJ):
	mkdir -p obj
	@echo "Making $@"
	$(GC) $(shell find src -type f -name $(notdir $*).c) -o obj/$(notdir $*).o $(INCLUDE) -c

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

rebuild: clean
	make -C dep CMD=re
	$(MAKE) re

re: clean
	$(MAKE) $(CMD)