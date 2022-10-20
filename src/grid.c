#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/grid.h"

grid *create_grid(int height, int width){
	grid *p_new_grid = malloc(sizeof(grid)); 
	p_new_grid->height = height;
	p_new_grid->width = width;
	cell *p_cells = malloc(sizeof(cell)*width*height); 
	p_new_grid->p_to_cell = p_cells;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			(p_cells + i * width + j)->visited = false;
			(p_cells + i * width + j)->open = false;
		}
	}	
	return p_new_grid;
}

void modify_visited(grid *p_new_grid, int i, int j, bool value) { 
	*access_visited(p_new_grid,i,j) = value;

}	

void modify_open(grid *p_new_grid, int i, int j, bool value) {
	*access_open(p_new_grid,i,j) = value;


}

bool *access_visited(grid *p_new_grid, int i, int j) {
	int width = p_new_grid->width;
	return &((p_new_grid->p_to_cell + i * width + j)->visited);
}

bool *access_open(grid *p_new_grid, int i, int j) {
	int width = p_new_grid->width;
	return &((p_new_grid->p_to_cell + i * width + j)->open);
}

void print_grid(grid * p_new_grid){
	int width;
	int height;
	cell *p_cells;
	width = p_new_grid->width;
	height = p_new_grid->height;
	p_cells = p_new_grid->p_to_cell;
	printf("%d %d\n",width, height);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if ((p_cells + i * width + j)->visited == true) {
				printf("X");
			}
			else if ((p_cells + i * width + j)->open == false) {
				printf("#");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");

	}
	printf("\n");
}











