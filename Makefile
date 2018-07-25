LIBS=-L lib  -L /goinfre/wgourley/.brew/Cellar/sdl2/2.0.8/lib

GC=gcc
LIB_CFG=$(realpath dep/libs.mk)
include project.mk dep/gen.mk
INCLUDE=-I lib/includes -I /goinfre/wgourley/.brew/include/

NAME=Wolf3D.bin

main: start

make: $(OBJS)
	$(GC) -o $(NAME) $(OBJS) $(INCLUDE) $(LIBS) -lmingw32 -mwindows  $(LINKS) -lSDL2main -lSDL2