#ifndef segment_h
#define segment_h

#include "ofMain.h"
#include "flPoint.h"

class Segment {
	private:


	public:
		Segment(ofVec2f _a, ofVec2f _b);
		Point pointA;
		Point pointB;
		ofVec2f getPointA();
		ofVec2f getPointB();
		ofVec2f getLerp(float _l);
		void show();
};

#endif