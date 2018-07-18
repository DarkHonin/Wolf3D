export SH
SH!="C:/Program\ Files/Git/usr/bin/sh.e"

LIBS=SDL

win:
	make -C SDL_BUILD_WIN
	cp SDL_BUILD_WIN/build/*.la ../lib
	mkdir -p ../lib/includes/SDL2
	cp SDL/include/*.h ../lib/includes/SDL2

config:
	for i in $(LIBS); do \
		cd $$i; \
		./configure --host=x86_64-w64-mingw32; \
	done