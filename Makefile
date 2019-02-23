all:
	gcc -Iinclude/ src/main.c src/vec_methods.c src/utils.c src/interpolation.c src/sort.c -lm -o numerical_methods_c -Wall -Wextra -Wpedantic