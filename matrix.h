//matrix.h
//Dyangelo Grullon (dag4202)

#ifndef MATRIX
#define MATRIX


typedef struct MatrixNode {
	int next;
	char action;
} MatrixNode;

typedef struct TransMatrix{
	MatrixNode** matrix;
	int states;
	int start;
	int accept;
}TransMatrix;

MatrixNode** buildEmptyMatrix(int rows, int cols);

void destroyMatrix(TransMatrix Tmat);

void printMatrix(TransMatrix Tmat);

TransMatrix buildMatrix(FILE *fp);
#endif
