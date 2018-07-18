
LIBS=$(realpath SDL)

win: sdl_win libft

sdl_win:
	make -C SDL_BUILD_WIN
	cp SDL_BUILD_WIN/build/.libs/libSDL2.a ../lib
	cp SDL_BUILD_WIN/build/.libs/libSDL2main.a ../lib
	rm -rf ../lib/includes/SDL2
	cp -r SDL/include ../lib/includes/SDL2

libft:
	make -C libft
	cp libft/libft.a ../lib
	cp libft/libft.h ../lib/includes

config_sdl_win:
	for i in $(LIBS); do \
		mkdir SDL_BUILD_WIN; \
		cd SDL_BUILD_WIN; \
		$$i/configure --host=x86_64-w64-mingw32; \
	done