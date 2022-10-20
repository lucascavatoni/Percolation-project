/**
 * @file image_generator.h
 *
 * @brief Simple program to generate an image from a grid
 *
 * @author Lucas Cavatoni
 * 
 * This is a simple program to generate a ppm image of grid.
 * Example:
 * Input name : /data/filename.txt
 * Output file : /out/filename.ppm
 *
 * The API of the IMAGE_GENERATOR is defined as follows:
 *
 * - a function to create a ppm image from a grid
 */

#ifndef IMAGE_GENERATOR_H
#define IMAGE_GENERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

/**
 * @brief Generates a .ppm image from a grid structure and from a desired filename
 *
 * @param my_grid  the pointer to the grid structure
 * @param filename[]  the desired filename with .txt extension virtually located in data/
 *
 * @post image of the grid 
 * 		-black is closed
 * 		-white is open
 * 		-red is visited 
 * the new filename is the old filename with a ppm (rather than txt) extension located in out/, see example above
 */
void generate_image(grid *my_grid, char filename[]); 
                                                  




#endif
