include libs.mk ../project.mk

make: $(LIB_DIR) $(ARCHIVES)
	@echo -n "Copying headers"
	@for i in $(LIBRAIRIES); do \
		cp -r $$i/includes $(LIB_DIR); \
		echo -n "."; \
	done
	@echo Done
	@echo -n "Copying archives"
	@for i in $(ARCHIVES); do \
		cp $$i $(LIB_DIR); \
		echo -n "."; \
	done
	@echo Done


$(ARCHIVES):
	@make -C $(dir $@) 

$(LIB_DIR):
	mkdir $(LIB_DIR)

re:
	@echo -n "Cleaning"
	@for i in $(LIBRAIRIES); do \
		make -C $$i fclean ;\
		echo -n "."; \
	done
	@echo Done
	@$(MAKE) make