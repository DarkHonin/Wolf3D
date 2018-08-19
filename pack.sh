#!/bin/sh

echo "Well hello there"
if [ "$1" == "pack" ]; then
	echo "packing"
	make fclean
	make -C dep fclean
	tar -cf dependency.tar dep
	tar -cf src.tar	srcs includes makefile map.w3
else
	echo "unpacking"
	tar -xf dependency.tar
	tar -xf src.tar
fi
