#include <stdio.h>
#include <stdlib.h>
#include "../include/image_generator.h"
#include "../include/grid.h"
#include "../include/loader.h"
#include <string.h>
#include <stdbool.h>

void generate_image(grid *my_grid, char filename[]) {
    FILE *p_file = NULL;
	
   	char *new_filename = calloc((strlen(filename)+4),8);
	for(int i = 0; i < strlen(filename)+3; i++){
		new_filename[i] = ' ';
	}
	

    new_filename[0] = 'o';
    new_filename[1] = 'u';
    new_filename[2] = 't';
    
    
    int i = 4;
    while (filename[i] != '.') {
		new_filename[i-1] = filename[i];
		i = i + 1;
	}
	int len = strlen(new_filename);
	new_filename[len-8] = '-';
	new_filename[len-7] = 'd';
	new_filename[len-6] = 'f';
	new_filename[len-5] = 's';
	new_filename[len-4] = '.';
	new_filename[len-3] = 'p';
	new_filename[len-2] = 'p';
	new_filename[len-1] = 'm';
   
    p_file = fopen(new_filename,"w");                                   
	
	free(new_filename);
	
    if (p_file == NULL) {
        fprintf(stderr, "Cannot write to file fact.txt!\n");
        exit(EXIT_FAILURE);
    }
    int height = my_grid->height;
    int width = my_grid->width;
	int sndline;
	sndline = 255;
	fprintf(p_file,"P3\n%d %d\n%d", width, height,sndline);

	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			if (*access_visited(my_grid, i, j) == true) {
				fprintf(p_file," %d %d %d", 255, 0, 0);
			}
			else if (*access_open(my_grid, i, j) == false) {
				fprintf(p_file," %d %d %d", 0, 0, 0);
			}
			else {
				fprintf(p_file," %d %d %d", 255, 255, 255);
			}
			fprintf(p_file,"\n");
		}
    }
    
    
    

    fclose(p_file);

    p_file = NULL;
}


