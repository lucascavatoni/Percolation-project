/**
 * @file union_find.h
 *
 * @brief Simple definition of the union-find structure
 *
 * @author Lucas Cavatoni
 * 
 * This is a simple program that defines the union-find structure
 * 
 * the API of the UNION_FIND is defined as follows:
 * 
 * -a function that creates a union-find grid
 * -a function that finds the root of an element
 * -a function that accesses the desired element of the grid
 * -a function that merges two elements of the grid
 */


#ifndef UNION_FIND_H
#define UNION_FIND_H

/**
 * @brief An alias to the structure representing an element
 */
typedef struct element element;

/**
 * @brief The structure representing an element of the union-find structure
 */
struct element {
	element *parent;
	int rank;
};

/**
 * @brief Creates a union-find structure where each element is rank 0 and points to itself
 *
 * @param height  the desired height of the grid 
 * @param width  the desired width of the grid
 *
 * @return a pointer to the first element of the union-find structure
 */
element *create_uf(int height,int width);

/**
 * @brief Finds the root of an element
 *
 * @param elt  the element you want to a find the root of
 *
 * @return a pointer to the root of the element elt
 */
element *find(element *elt);

/**
 * @brief accesses the element (i,j) of the union-find structure
 *
 * @param uf_grid the union-find grid structure
 * @param width the width of the union-find grid structure
 * @param i the desired row of the element
 * @param j the desired column of the element
 *
 * @return a pointer to the element(i,j) of the union-find grid structure
 */
element *access_element(element *uf_grid, int width, int i, int j);

/**
 * @brief merges elt11 and elt2 in a grid
 *
 * @param elt1  the first element
 * @param elt2 the second element
 *
 * @post elt1 and elt2 are merged: they have the same root, if they had the same rank: elt1's rank is incremented by 1.
 */
void merge(element *elt1,element *elt2);

#endif