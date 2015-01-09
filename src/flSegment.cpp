#include "flSegment.h"


Segment::Segment(ofVec2f _a, ofVec2f _b){
	pointA.set(_a);
	pointB.set(_b);	
	//cout << "flSegment.cpp: new segment: " << pointA << ' ' << pointB << endl;
}

ofVec2f Segment::getPointA(){
	return pointA.get();//.getPos();
}

ofVec2f Segment::getPointB(){
	return pointB.get();//.getPos();
}

ofVec2f Segment::getLerp(float _l){
	ofVec2f v;
	v.set(pointA.get());
	v.interpolate(pointB.get(), _l);
	return v;
}
void Segment::show(){
	ofLine(pointA.get(), pointB.get()); 
}