#ifndef _SCANNER_H_
#define _SCANNER_H_
#include "matrix.h"

/**
classifies a character
@param c the character to be classified
*/
int classifier (char c);

/**
uses rules described in a transition matrix to scan input
and recognize tokens
@param Tmat the transition matrix
*/
int scanner(TransMatrix Tmat);


#endif
