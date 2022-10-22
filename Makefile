CC = gcc
CFLAGS = -g -std=c99 -Wall -Werror -O3 

test-loader: src/test-loader.c src/grid.c include/grid.h
	$(CC) $(CFLAGS) -o test-loader.o src/test-loader.c src/grid.c
	./test-loader.o data/grid_visited.txt
		
test-generate-image: src/test-generate-image.c src/image_generator.c include/image_generator.h src/loader.c include/loader.h src/grid.c include/grid.h
	$(CC) $(CFLAGS) -o test-generate-image.o src/test-generate-image.c src/image_generator.c src/loader.c src/grid.c
	./test-generate-image.o

test-percolate: src/test-percolate.c src/percolate_dfs.c include/percolate_dfs.h src/image_generator.c include/image_generator.h src/grid.c include/grid.h src/loader.c include/loader.h
	$(CC) $(CFLAGS) -o test-percolate.o src/test-percolate.c src/image_generator.c src/percolate_dfs.c src/loader.c src/grid.c
	./test-percolate.o

threshold-dfs: src/threshold-dfs.c src/monte_carlo_dfs.c include/monte_carlo_dfs.h src/percolate_dfs.c include/percolate_dfs.h src/image_generator.c include/image_generator.h src/grid.c include/grid.h src/loader.c include/loader.h
	$(CC) $(CFLAGS) -o threshold-dfs.o src/threshold-dfs.c src/monte_carlo_dfs.c src/image_generator.c src/percolate_dfs.c src/loader.c src/grid.c
	./threshold-dfs.o

test-union-find-correctness: src/union_find.c src/test-union-find-correctness.c include/union_find.h
	$(CC) $(CFLAGS) -o test-union-find-correctness.o src/test-union-find-correctness.c src/union_find.c
	./test-union-find-correctness.o

test-union-find-complexity: src/union_find.c src/test-union-find-complexity.c include/union_find.h
	$(CC) $(CFLAGS) -o test-union-find-complexity.o src/test-union-find-complexity.c src/union_find.c
	./test-union-find-complexity.o

threshold-uf: src/threshold-uf.c src/union_find.c src/monte_carlo_uf.c include/union_find.h include/monte_carlo_uf.h src/grid.c include/grid.h src/image_generator.c include/image_generator.h
	$(CC) $(CFLAGS) -o threshold-uf.o src/threshold-uf.c src/monte_carlo_uf.c src/union_find.c src/grid.c src/image_generator.c
	./threshold-uf.o
	
compile-all: test-loader test-generate-image test-percolate test-union-find-correctness test-union-find-complexity threshold-uf threshold-dfs		
	
valgrind-loader: test-loader.o data/grid_visited.txt
	valgrind --leak-check=full ./test-loader.o data/grid_visited.txt
	
valgrind-image: test-generate-image.o
	valgrind --leak-check=full ./test-generate-image.o
	
valgrind-percolate: test-percolate.o
	valgrind --leak-check=full ./test-percolate.o
	
valgrind-threshold: threshold-dfs.o
	valgrind --leak-check=full ./threshold-dfs.o

valgrind-uf-corr: test-union-find-correctness.o
	valgrind --leak-check=full ./test-union-find-correctness.o

valgrind-uf-comp: test-union-find-complexity.o
	valgrind --leak-check=full ./test-union-find-complexity.o

valgrind-uf: threshold-uf.o
	valgrind --leak-check=full ./threshold-uf.o
