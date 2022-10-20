#include "../include/union_find.h"
#include "../include/monte_carlo_uf.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/grid.h"

bool percolate(element *virtual_bottom, element *virtual_top){
    if (find(virtual_bottom) == find(virtual_top)){
        return true;
    }  
    else{
        return false;
    }
}

int open_cells(grid *my_grid){
	int cellsopen = 0;
	int width = my_grid->width;
	int height = my_grid->height;
    element *my_ufgrid = create_uf(height,width);
    element *virtual_bottom = calloc(1,sizeof(element));
    element *virtual_top = calloc(1,sizeof(element));
    virtual_top->parent = virtual_top;
    virtual_bottom->parent = virtual_bottom;
    virtual_top->rank = 0;
    virtual_bottom->rank = 0;
    for(int i = 0; i < width; i++){
        merge(virtual_top,my_ufgrid + i);
        merge(virtual_bottom,my_ufgrid + (width-1)*width + i);
    }
	while (percolate(virtual_bottom,virtual_top) == false){
		int j = rand() % width;
		int i = rand() % height;
		while (*access_open(my_grid,i,j) == true) {
			j = rand() % width;
			i = rand() % height;
		}
		modify_open(my_grid,i,j,true);
		cellsopen = cellsopen + 1;
		element *elt1 = calloc(1,sizeof(element));
		elt1 = access_element(my_ufgrid,width,i,j);
		element *elt2 = calloc(1,sizeof(element));
        if (j != 0 && *access_open(my_grid,i,j-1) == true){
            elt2 = access_element(my_ufgrid,width,i,j-1);
            merge(elt1,elt2);
        }
        if (j < width - 1 && *access_open(my_grid,i,j+1) == true){
            elt2 = access_element(my_ufgrid,width,i,j+1);
            merge(elt1,elt2);
        }
        if (i != 0 && *access_open(my_grid,i-1,j) == true){
            elt2 = access_element(my_ufgrid,width,i-1,j);
            merge(elt1,elt2);
        }
        if (i < height - 1 && *access_open(my_grid,i+1,j) == true){
            elt2 = access_element(my_ufgrid,width,i+1,j);
            merge(elt1,elt2);
        }
	}
	free(virtual_top);
	free(virtual_bottom);
    free(my_grid->p_to_cell);
    free(my_grid);
    free(my_ufgrid);
	return cellsopen;
}

  
       
   
     
