#include "../include/union_find.h"
#include "../include/grid.h"
#include <stdio.h>
#include "../include/monte_carlo_uf.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	double time_spent = 0.0;
	clock_t begin = clock();
	float threshold = 0;
	int seed = 1024;
	srand(seed);
	for(int i = 1; i <= 50; i++){
		grid *test_grid = create_grid(300,300); 
		int cellsopen = open_cells(test_grid); 
		printf("%d\n", cellsopen);
		threshold = threshold + (float)cellsopen/90000/50;
	}
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Threshold = %f\n",threshold);
	printf("Time elapsed with union find is %f seconds\n", time_spent);
	return 0;
}
