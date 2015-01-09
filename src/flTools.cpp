#include "flTools.h"

int wrap(int n, int s){
	if(n<0) n = s;
	else if(n > s) n = 0;
	return n;
}

float floatWrap(float _f){
	if(_f > 1) _f -=1;
	else if(_f < 0) _f += 1;
	return _f;
}