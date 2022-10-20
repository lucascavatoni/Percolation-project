#include "../include/percolate_dfs.h"
#include <stdbool.h>
#include <assert.h>
#include "../include/grid.h"
#include <stdlib.h>
#include <stdio.h>

bool percolate(grid *my_grid) {
	bool result = false;
	int width = my_grid->width;
	int j = 0;
	while (j < width) {
		if (*access_open(my_grid,0,j) == false){
		}
		else {
			modify_visited(my_grid,0,j,true);
			if (j == 0){
				result = percolate_left(my_grid,0,j);
			}
			else if (j == width-1){
				result = percolate_right(my_grid,0,j);
			}
			else {
				result = percolate_middle(my_grid,0,j);
			}
		}
		j = j + 1; 
		if (result == true){
			return true;
		}
	}
	return result;
}

bool percolate_middle(grid *my_grid,int i,int j){
	bool result = false;
	modify_visited(my_grid,i,j,true);
	int height = my_grid->height;
	int width = my_grid->width;
	if (*access_visited(my_grid,i+1,j) == false && *access_open(my_grid,i+1,j) == true) {
		if (i == height - 2){
			modify_visited(my_grid,i+1,j,true);
			return true;
		}
		else {
			result = percolate_middle(my_grid,i+1,j);
		}
	}
	if (result == false && *access_visited(my_grid,i,j-1) == false && *access_open(my_grid,i,j-1) == true) {
		if (j == 1){
			result = percolate_left(my_grid,i,j-1);
		}
		else {
			result = percolate_middle(my_grid,i,j-1);
		}
	}
	if (result == false && *access_visited(my_grid,i,j+1) == false && *access_open(my_grid,i,j+1) == true){
		if (j == width - 2) {
			result = percolate_right(my_grid,i,j+1);
		}
		else {
			result = percolate_middle(my_grid,i,j+1);
		}
	}		
	if (i > 0 && result == false && *access_visited(my_grid,i-1,j) == false && *access_open(my_grid,i-1,j) == true){
		if (i == 1){
			return false;
		}
		else {
			return percolate_middle(my_grid,i-1,j);
		}
	}
	else {
		return result;
	}
}


bool percolate_left(grid *my_grid,int i,int j){
	bool result = false;
	modify_visited(my_grid,i,j,true);
	int height = my_grid->height;
	if (*access_visited(my_grid,i+1,j) == false && *access_open(my_grid,i+1,j) == true) {
		if (i == height - 2){
			modify_visited(my_grid,i+1,j,true);
			return true;
		}
		else {
			result = percolate_left(my_grid,i+1,j);
		}
	}
	if (result == false && *access_visited(my_grid,i,j+1) == false && *access_open(my_grid,i,j+1) == true){
		result = percolate_middle(my_grid,i,j+1);
	}
	if (i > 0 && result == false && *access_visited(my_grid,i-1,j) == false && *access_open(my_grid,i-1,j) == true){
		if (i == 1){
			return false;
		}
		else {
			return percolate_left(my_grid,i-1,j);
		}
	}
	else {
		return result;
	}
}
	
bool percolate_right(grid *my_grid,int i,int j){
	bool result = false;
	modify_visited(my_grid,i,j,true);
	int height = my_grid->height;
	if (*access_visited(my_grid,i+1,j) == false && *access_open(my_grid,i+1,j) == true) {
		if (i == height - 2){
			modify_visited(my_grid,i+1,j,true);
			return true;
		}
		else {
			result = percolate_right(my_grid,i+1,j);
		}
	}
	if (result == false && *access_visited(my_grid,i,j-1) == false && *access_open(my_grid,i,j-1) == true){
		result = percolate_middle(my_grid,i,j-1);
	}
	if (i > 0 && result == false && *access_visited(my_grid,i-1,j) == false && *access_open(my_grid,i-1,j) == true){
		if (i == 1){
			return false;
		}
		else {
			return percolate_right(my_grid,i-1,j);
		}
	}
	else {
		return result;
	}
}			
	
	








	


