//tokenize.c
//author: Dyangelo Grullon (dag4202)
#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "scanner.h"

int main(int argc, char * argv[]){
	if (argc!=2){
		fprintf(stderr, "usage: ./tokenize tmfile\n");
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
		while(scanner(Tmat)!=EOF){}
		destroyMatrix(Tmat);
		fclose(fp);
	}

}
