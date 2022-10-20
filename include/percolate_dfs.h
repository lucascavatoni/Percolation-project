/**
 * @file percolate_dfs.h
 *
 * @brief Simple program tells you if a grid percolates or not
 *
 * @author Lucas Cavatoni
 * 
 * This is a simple program to tell if a grid percolates ot not
 * 
 * the API of the PERCOLATE_DFS is defined as follows:
 * 
 * -a function that says if a grid percolates
 * -a function that says if, starting from a left cell wall, the grid percolates
 * -a function that says if, starting from a right cell wall, the grid percolates
 * -a function that says if, starting from a cell in the middle, the grid percolates
 * 
 */

#ifndef PERCOLATE_DFS_H
#define PERCOLATE_DFS_H
#include <stdbool.h>
#include "grid.h"


/**
 * @brief Does a grid percolate?
 *
 * @param my_grid  the pointer to the grid structure (a closed and unvisited grid)
 * 
 * @return true/false   if the grid percolates
 */
bool percolate(grid *my_grid);                      

/**
 * @brief Does a grid percolate from a cell in the left wall?
 *
 * @param my_grid  the pointer to the grid structure (a closed and unvisited grid)
 * @param i  row 
 * @param j  column but in this case j is equal to 0 because we are on a left wall
 * 
 * @return true/false   if the grid percolates from a cell in the left wall
 */
bool percolate_left(grid *my_grid,int i,int j);  

/**
 * @brief Does a grid percolate from a cell in the middle section (so not in a right wall nor a left wall)?
 *
 * @param my_grid  the pointer to the grid structure (a closed and unvisited grid)
 * @param i  row 
 * @param j  column but in this case j is equal to (width-1) because we are on a right wall
 * 
 * @return true/false   if the grid percolates from a cell in the middle
 */
bool percolate_middle(grid *my_grid,int i,int j);	

/**
 * @brief Does a grid percolate from a cell in the right wall?
 *
 * @param my_grid  the pointer to the grid structure (a closed and unvisited grid)
 * @param i  row 
 * @param j  column but in this case j is equal to (width-1) because we are on a right wall
 * 
 * @return true/false   if the grid percolates from a cell in the right wall
 */
bool percolate_right(grid *my_grid,int i,int j);      

#endif
