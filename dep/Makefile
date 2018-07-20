LIBFT="$(realpath libft)"
GNL="$(realpath gnl)"
VECT="$(realpath vect_ft)"

HEADERS=$(GNL)/get_next_line.h $(LIBFT)/libft.h $(VECT)/vect_ft.h

LIBS=$(LIBFT) $(GNL) $(VECT)

ARCH=$(LIBFT)/libft.a $(GNL)/gnl.a $(VECT)/libvect.a

make:
	@for i in $(LIBS); do \
		make -C $$i LIBFT=$(LIBFT) CMD=$(CMD); \
	done
	@for i in $(HEADERS); do \
		cp $$i ../lib/includes; \
	done
	@for i in $(ARCH); do \
		cp $$i ../lib; \
	done