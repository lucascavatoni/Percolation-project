/**
 * @file grid.h
 *
 * @brief Simple definition of grid and cell structures
 *
 * @author Lucas Cavatoni
 * 
 * This is a simple definition of a grid structure, along with cell structures which are
 * the cells of the grid. 
 *
 * The API of the GRID is defined as follows:
 *
 * - a function to create a closed grid
 * - a function to modify the open value of a cell
 * - a function to modify the visited value of a cell
 * - a function to access the open value of a cell
 * - a function to access the open value of a cell
 * - a function to print the grid
 */

#ifndef GRID_H
#define GRID_H

#include <stdbool.h>

/**
 * @brief An alias to the structure representing the grid
 */
typedef struct grid grid;

/**
 * @brief An alias to the structure representing the cell
 */
typedef struct cell cell;

/**
 * @brief The structure representing the grid
 */
struct grid {
	int height;        
	int width;         
	cell * p_to_cell;  
};


/**
 * @brief The structure representing a cell
 */
struct cell {
	bool open;    
	bool visited; 

};

/**
 * @brief Creates a closed (and not visited) grid
 *
 * @param width  the desired width of the grid
 * @param height  the desired height of the grid 
 *
 * @return a pointer to the structure grid created with all closed cells
 */
grid *create_grid(int width, int height);                        

/**
 * @brief Modifies the visited value of a grid
 *
 * @param p_new_grid  the pointer to the grid structure
 * @param i  the desired row at which the value will be modified
 * @param j  the desired column at which the value will be modified
 * @param value  'true' or 'false', the value to give to the state 'visited'
 *
 * @post  the visited value of element [i][j] of the grid is now either true or false, 
 * depending on the value input
 */
void modify_visited(grid *p_new_grid, int i, int j, bool value); 

/**
 * @brief Modifies the open/closed value of a grid
 *
 * @param p_new_grid  the pointer to the grid structure
 * @param i  the desired row at which the value will be modified
 * @param j  the desired column at which the value will be modified
 * @param value  'true' to open the cell, 'false' to close the cell
 *
 * @post  the open value of element [i][j] of the grid is now either true or false, 
 * depending on the value input
 */
void modify_open(grid *p_new_grid, int i, int j, bool value);    

/**
 * @brief accesses the open/closed value of element row i, column j of the grid
 *
 * @param p_new_grid  the pointer to the grid structure
 * @param i  the desired row at which the value will accessed
 * @param j  the desired column at which the value will be accessed
 *
 * @return  the pointer to the value open/closed of the desired cell
 */
bool *access_open(grid *p_new_grid, int i, int j);               


/**
 * @brief accesses the visited value of element row i, column j of the grid
 *
 * @param p_new_grid  the pointer to the grid structure
 * @param i  the desired row at which the value will accessed
 * @param j  the desired column at which the value will be accessed
 *
 * @return  the pointer to the value visited of the desired cell
 */
bool *access_visited(grid *p_new_grid, int i, int j);           

/**
 * @brief accesses the visited value of element row i, column j of the grid
 *
 * @param p_new_grid  the pointer to the grid structure
 * @param i  the desired row at which the value will accessed
 * @param j  the desired column at which the value will be accessed
 *
 * @post  prints the grid in the terminal with 'X' visited cell, '#' closed cell and ' ' open cell 
 */
void print_grid(grid * p_new_grid);                              


#endif


