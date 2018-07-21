LIBFT="$(realpath libft)"
GNL="$(realpath gnl)"
VECT="$(realpath vect_ft)"
MATRIX="$(realpath matrix)"

HEADERS=$(GNL)/get_next_line.h $(LIBFT)/libft.h $(VECT)/vect_ft.h $(MATRIX)/matrix_ft.h

LIBS=$(LIBFT) $(GNL) $(VECT) $(MATRIX)

ARCH=$(LIBFT)/libft.a $(GNL)/libgnl.a $(VECT)/libvect.a $(MATRIX)/libmatrix.a

make:
	@for i in $(LIBS); do \
		echo "Doing $$i : $(CMD)"; \
		make -C $$i LIBFT=$(LIBFT) $(CMD); \
	done
	@for i in $(HEADERS); do \
		cp $$i ../lib/includes; \
	done
	@for i in $(ARCH); do \
		cp $$i ../lib; \
	done
