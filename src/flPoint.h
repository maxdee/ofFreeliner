#ifndef point_h
#define point_h

#include "ofMain.h"

class Point {
	private:
		ofVec3f pos;
		//second pos?

	public:
		Point();

		void nudge(ofVec3f _p);
		bool checkProx(int _d, ofVec3f _p);
		void set(ofVec3f _p);
		ofVec3f get();

};

#endif
