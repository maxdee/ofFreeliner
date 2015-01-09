#include "flPoint.h"

Point::Point(){//ofVec2f _p){
	// pos.set(_p);

}

void Point::nudge(ofVec2f _p){
	pos += _p;
}

bool Point::checkProx(int _d, ofVec2f _p){
	if(pos.distance(_p) < _d) return true;
	else return false;
}

void Point::set(ofVec2f _p){
	pos.set(_p);
}

ofVec2f Point::get(){
	return pos;
}


