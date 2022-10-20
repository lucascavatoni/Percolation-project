#include <stdio.h>
#include <stdlib.h>
#include "../include/image_generator.h"
#include "../include/loader.h" 

int main(void){
	char filename[] = "data/grid_visited.txt";
	grid *test_grid = load(filename);
	generate_image(test_grid, filename);
	free(test_grid->p_to_cell);
	free(test_grid);
	return 0;
}
