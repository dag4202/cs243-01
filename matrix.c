//matrix.c
//author: Dyangelo Grullon (dag4202)
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "classes.h"
#include "matrix.h"
#include <assert.h>

MatrixNode** buildEmptyMatrix(int rows, int cols){
	MatrixNode **matrix =  malloc(sizeof(MatrixNode *) * rows);
	assert(matrix!=NULL);
	for (int i=0; i < rows; i++){
		matrix[i] = malloc(sizeof(MatrixNode) * cols);
		assert(matrix[i]!=NULL);
		for(int j=0; j<cols; j++){
			matrix[i][j].next = 99;
			matrix[i][j].action='d';
		}
	}
	return matrix;
}

void destroyMatrix(TransMatrix Tmat){
	MatrixNode** matrix = Tmat.matrix;
	assert(matrix!=NULL);
	for (int i=0; i<Tmat.states; i++){
		assert(matrix[i]!=NULL);
		free(matrix[i]);
	}
	free (matrix);
}
void printMatrix(TransMatrix Tmat){
	int next;
	char action;
	MatrixNode **matrix = Tmat.matrix;
	printf("Scanning using the following matrix:\n");
	printf("     0    1    2    3    4    5    6    7    8    9   10   11\n");
	for (int i = 0; i<Tmat.states;i++){
		if (i<10){
			printf(" %d",i);
		} else {
			printf("%d",i);
		}
		for(int j = 0; j<N_CC;j++){
			next = matrix[i][j].next;
			action = matrix[i][j].action;
			if (next <10){
				printf("   %d%c",next, action); 
			} else {
				printf("  %d%c", next, action);
			}
		}
		printf("\n");
	}
} 
TransMatrix buildMatrix(FILE *fp){
	char *ptr, buf[256];
	char *token;
	TransMatrix Tmat;
	for (int i = 0; i<3; i++){
		ptr = fgets(buf, 256, fp);
		token = strtok(ptr," ");
		if (i==0){
			Tmat.states = atoi(token = strtok(NULL," "));
		} else if (i==1) {
			Tmat.start = atoi(token = strtok(NULL, " "));
		} else {
			Tmat.accept = atoi(token = strtok(NULL, " "));
		}
	}
	Tmat.matrix = buildEmptyMatrix(Tmat.states, N_CC);
	int row;
	int col;
	int next;
	char action;
	while((ptr = fgets(buf, 256, fp)) != NULL){
		token = strtok(ptr," ");
		row = atoi(token);
		while((token = strtok(NULL," "))!=NULL){
			sscanf(token, "%d/%d%c", &col, &next,
				 &action);
			Tmat.matrix[row][col].next = next;
			Tmat.matrix[row][col].action = action;
		}
	}
	
	return Tmat;
}
