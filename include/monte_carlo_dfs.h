/**
 * @file monte_carlo_dfs.h
 *
 * @brief Simple program to give the number of open cells needed for a random grid to percolate 
 *
 * @author Lucas Cavatoni
 * 
 * This is a simple program gives the number of open cells needed for a random grid to percolate
 * The function will randomly open cells in the grid until the grid percolates, then it will return the number of open cells
 *
 * The API of the MONTE_CARLO_DFS is defined as follows:
 *
 * - a function to give the number of open cells needed for a random grid to percolate
 */

#ifndef MONTE_CARLO_DFS_H
#define MONTE_CARLO_DFS_H
#include "grid.h"
#include <stdbool.h>


/**
 * @brief Gives the number of open cells needed for a random grid to percolate
 *
 * @param my_grid  the pointer to the grid structure (a closed and unvisited grid)
 * 
 * @return The number of cells needed for the grid to percolate
 */
int open_cells(grid *my_grid);


#endif
