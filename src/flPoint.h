#ifndef point_h
#define point_h

#include "ofMain.h"

class Point {
	private:
		ofVec2f pos;
		//second pos?

	public:
		Point();//ofVec2f _p);

		void nudge(ofVec2f _p);
		bool checkProx(int _d, ofVec2f _p);

		void set(ofVec2f _p);
		ofVec2f get();
		
};

#endif