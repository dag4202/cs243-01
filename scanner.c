//scanner.c
//author: Dyangelo Grullon (dag4202)
#include "scanner.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "classes.h"
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
	}else if (c>=32){
		return CC_OTHER;
	}else if (c==EOF){
		return CC_EOF;
	}else {
		return CC_ERROR;
	}
}
int scanner(TransMatrix Tmat){
	int start = Tmat.start;
	int accept = Tmat.accept;
	int current = start;
	int charClass;
	char c;
	char *buff = malloc (2);
	int stringcount = 1;
	MatrixNode node;
	while (current!=accept && current!=99){
		c= getchar();
		printf("%d ", current);
		charClass =  classifier(c);
		node = Tmat.matrix[current][charClass];
		if (node.action=='s'){
			stringcount++;
			buff = realloc(buff,stringcount +1);
			sprintf(buff,"%s%c", buff, c); 
		}
		current = node.next;
	}
	printf("%d ", current);
	if (current==accept && charClass==CC_EOF){
		printf("EOF\n");
		free(buff);
		return EOF;
	} else if (current==accept){
		printf("recognized '%s'\n", buff);
		free(buff);
		return 1;
	} else {
		printf("rejected\n");
		while ((c=getchar())!=' '){}
		free(buff);
		return 0;
	}

}
