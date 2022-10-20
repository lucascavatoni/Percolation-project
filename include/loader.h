/**
 * @file loader.h
 *
 * @brief Simple program to load a txt file and generate a grid
 *
 * @author Lucas Cavatoni
 * 
 * This is a simple program to generate a grid from a txt file
 *
 * The API of the LOADER is defined as follows:
 *
 * - a function to create a grid from a txt file
 */

#ifndef LOADER_H
#define LOADER_H

#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

/**
 * @brief Generates a grid from a txt file
 *
 * @param p_filename the file you want to generate a grid from
 * 
 * @return a pointer to a grid structure 
 * 		'#' gives a closed cell
 * 		'X' gives a visited cell
 * 		' ' gives an open cell
 */
grid *load(char *p_filename);  

#endif
