#include "../include/grid.h"
#include "../include/loader.h"
#include "../include/image_generator.h"
#include "../include/percolate_dfs.h"
#include <stdio.h>
#include <stdbool.h>

int main(void) {
	for(int i = 1; i < 6; i++){
		char filename[21];
		sprintf(filename,"data/grid_np_%d.txt",i);
		grid *test_grid = load(filename);
		bool percolateYN = percolate(test_grid);
		generate_image(test_grid,filename);
		if (percolateYN == false) {
			printf("grid_np_%d.txt does not percolate\n",i);
		}
		else{
			printf("grid_np_%d.txt does percolate\n",i);
		}
		free(test_grid->p_to_cell);
		free(test_grid);
	}
	for(int i = 1; i < 11; i++) {
		char filename[20];
		sprintf(filename,"data/grid_p_%d.txt",i);
		grid *test_grid = load(filename);
		bool percolateYN = percolate(test_grid);
		generate_image(test_grid,filename);
		if (percolateYN == false) {
			printf("grid_p_%d.txt does not percolate\n",i);
		}
		else{
			printf("grid_p_%d.txt does percolate\n",i);
		}
		free(test_grid->p_to_cell);
		free(test_grid);
	}
	
		
	return 0;
}
