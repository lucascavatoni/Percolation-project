#include <stdlib.h>
#include "../include/union_find.h"

element *create_uf(int height, int width){
	element *p_elements = malloc(sizeof(element)*height*width);
	for (int i = 0; i < height*width; i++){
			(p_elements + i)->parent = p_elements + i;
			(p_elements + i)->rank = 0;
	}
	return p_elements;
}
	
element *find(element *elt){
	if ((elt)->parent != elt){
		(elt)->parent = find((elt)->parent);
	}
	return (elt)->parent;
}

element *access_element(element *uf_grid, int width, int i, int j){
	return (uf_grid + i * width + j);
}
	
void merge(element *elt1,element *elt2){
	element *elt1_root = find(elt1);
	element *elt2_root = find(elt2);
	if (elt1_root != elt2_root){
		if (elt1_root->rank < elt2_root->rank){
			elt1_root->parent = elt2_root;
		}
		else{
			elt2_root->parent = elt1_root;
			if (elt1_root->rank == elt2_root->rank){
				elt1_root->rank = elt1_root->rank + 1;
			}
		}
	}
}



