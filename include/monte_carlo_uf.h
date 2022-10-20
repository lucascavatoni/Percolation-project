/**
 * @file monte_carlo_uf.h
 *
 * @brief Simple algorithm that gives the number of cell to open for the grid to percolate,
 *        using a union find structure
 *
 * @author Lucas Cavatoni
 *
 * This is a simple program that gives the number of cell to open for the grid to percolate, using a union find structure
 * 
 * the API of the MONTE_CARLO_UF is defined as follows:
 * 
 * -a function that checks if the grid percolates using union-find
 * -a function that returns the number of cells for the grid to percolate
 * 
 */

#ifndef MONTE_CARLO_UF_H
#define MONTE_CARLO_UF_H
#include <stdbool.h>
#include "../include/grid.h"

/**
 * @brief Gives the number of open cells needed for a random grid to percolate
 *
 * @param my_grid  the pointer to the grid structure (a closed and unvisited grid)
 * 
 * @return The number of cells needed for the grid to percolate
 */
int open_cells(grid *my_grid);

/**
 * @brief Checks wether or not the grid percolates, using a union-find structure.
 *
 * @param virtual_bottom all the union-find cells of the last row are now merged with virtual_bottom
 * @param virtual_top all the union-find cells of the first row are merged with virtual_top : 
 *                    virutal_top is the parent of all the cells of the first row :
 *                    all the cells of the first row point to virtual_top
 * 
 * @return true/false, true if the grid percolates : if the union-find grid percolates : 
 *         if one cell of the bottom is linked to a cell on the top :
 *         if one cell of the bottom has the same root as a cell on the top :
 *         if virtual_bottom and virtual_top have the same root
 */
bool percolate(element *virtual_bottom, element *virtual_top);

#endif