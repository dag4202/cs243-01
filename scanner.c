//Dyangelo Grullon (dag4202)
//scanner.c
#include "scanner.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int classifier(char c){
	if(c==' ' || c =='\t'){
		return CC_WS;
	} else if (c=='\n'){
		return CC_NEWLINE;
	} else if((c<=90 && c>=65) || (c==95) || (c>=97 && c<=122)){
		return CC_ALPHA;
	} else if (c==48){
		return CC_DIG_0;
	} else if (c>=49 && c<=55){
		return CC_DIG_1_7;
	} else if (c=='8' || c=='9') {
		return CC_DIG_8_9;
	} else if (c=='/'){
		return CC_CHAR_SLASH;
	}else if (c=='*'){
		return CC_CHAR_STAR;
	}else if (c=='+' || c=='-' || c=='%'){
		return CC_ARITH_OP;
	}else if (isascii(c)){
		return CC_OTHER;
	}else if (c==EOF){
		return CC_EOF;
	}else {
		return CC_ERROR;
	}
}
char *scanner(TransMatrix Tmat){
	int start = Tmat.start;
	int accept = Tmat.accept;
	int current = start;
	

}
