#include <stdlib.h>
#include "../include/grid.h"
#include <stdbool.h>
#include <stdio.h>
#include "../include/percolate_dfs.h"
#include "../include/grid.h"
#include <stdbool.h>


int open_cells(grid *my_grid){
	int cellsopen = 0;
	int width = my_grid->width;
	int height = my_grid->height;
	while (percolate(my_grid) == false){
		int j = rand() % width;
		int i = rand() % height;
		while (*access_open(my_grid,i,j) == true) {
			j = rand() % width;
			i = rand() % height;
		}
		modify_open(my_grid,i,j,true);
		cellsopen = cellsopen + 1;
		for (int i = 0; i < height-1; i++){
			for(int j = 0; j < width; j++) {
				modify_visited(my_grid,i,j,false);
			}
		}
	}
	for (int i = 0; i < height; i++){
		for(int j = 0; j < width; j++) {
			modify_visited(my_grid,i,j,false);
		}
	}
	percolate(my_grid);
	return cellsopen;
}
