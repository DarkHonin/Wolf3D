PROJECT=$(realpath .)
LIB_DIR=$(realpath lib)
INCLUDE_DIR=$(realpath lib/includes)
make:
	@rm project.mk
	@echo "PROJECT=$(PROJECT)" >> project.mk;
	@echo "LIB_DIR=$(LIB_DIR)" >> project.mk;
	@echo "INCLUDE_DIR=$(INCLUDE_DIR)" >> project.mk