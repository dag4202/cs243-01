//matrix.h
//Dyangelo Grullon (dag4202)

#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <stdio.h>

/**
MatrixNode
a node within the Transition Matrix. Holds the next state and action
*/
typedef struct MatrixNode {
	int next;
	char action;
} MatrixNode;

/**
Encapsulator for Transition Matrix. Holds the matrix, number of states,
the starting state and the accepting state
*/
typedef struct TransMatrix{
	MatrixNode** matrix;
	int states;
	int start;
	int accept;
}TransMatrix;

/**
builds an empty transition matrix
@param rows the number of rows desired
@param cols the number of columns desired
@returns a double pointer to a matrix node, with default settings
*/
MatrixNode** buildEmptyMatrix(int rows, int cols);

/**
frees dynamically allocated transition matrix
@param Tmat the transition matrix
*/
void destroyMatrix(TransMatrix Tmat);

/**
prints data associated with a transition matrix
@param Tmat the transition matrix
*/
void printMatrix(TransMatrix Tmat);

/**
opens a file and reads data to build and print a completed transition matrix
@param fp the file to read from
*/
TransMatrix buildMatrix(FILE *fp);
#endif
