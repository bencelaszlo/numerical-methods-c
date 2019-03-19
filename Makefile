all:
	gcc -O3 -Iinclude/ src/main.c src/vec_methods.c src/utils.c src/interpolation.c src/integration.c src/sort.c -lm -o numerical_methods_c -Wall -Wextra -Wpedantic