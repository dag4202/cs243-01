//Dyangelo Grullon (dag4202)
#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"


int main(int argc, char * argv[]){
	if (argc==1){
		printf("usage: ./tokenize tm_file\n");
		exit(1);
	} else {
		FILE *fp; 
		fp = fopen(argv[1], "r");
		if (fp == NULL) {
			perror(argv[1]);
			exit(1);
		}
		TransMatrix Tmat = buildMatrix(fp);
		printMatrix(Tmat);
		destroyMatrix(Tmat);
	}

	return 1;
}
