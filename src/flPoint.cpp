#include "flPoint.h"

Point::Point(){

}

void Point::nudge(ofVec3f _p){
	pos += _p;
}

bool Point::checkProx(int _d, ofVec3f _p){
	if(pos.distance(_p) < _d) return true;
	else return false;
}

void Point::set(ofVec3f _p){
	pos.set(_p);
}

ofVec3f Point::get(){
	return pos;
}
