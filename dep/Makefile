include libs.mk
LIBDIR=$(realpath .)
prep:
	@for i in $(LIBRAIRIES); do \
		echo "Making: $$i"; \
		make -C $$i LIBDIR=$(LIBDIR) -s; \
	done

fclean:
	@echo -n "Cleaning"
	@for i in $(LIBRAIRIES); do \
		make -C $$i fclean -s;\
		echo -n "."; \
	done
	@echo Done

re:
	@echo "Rebuilding..."
	@for i in $(LIBRAIRIES); do \
		make -C $$i re LIBDIR=$(LIBDIR) -s ;\
	done