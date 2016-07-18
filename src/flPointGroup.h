#ifndef flPointGroup_h
#define flPointGroup_h

#include "ofMain.h"
#include "flSegment.h"
#include "flTools.h"

class PointGroup {
	private:
		void startSegment(ofVec3f _p);
		void endSegment(ofVec3f _p);
		void placeCenter(ofVec3f _p);
		void unCenter();
		void undo();

	public:
		PointGroup();
		void init(int &_id);
		//~PointGroup();

		void mousePress(int _b, ofVec3f _p);
		void keyPress(int _k);
		void gui(ofVec3f _p, ofTrueTypeFont _tt);
		void decorate(float _f);

		void snapNudge(float _d, ofVec3f _p, ofVec3f _n);
		void nudgeLast(ofVec3f _n);
		ofVec3f findNear(float _d, ofVec3f _p);

		//////////// was private
		ofVec3f previousPos;
		int ident;
		int segCount;
		int polka;
		float fluct;
		vector<Segment> segments;
		bool putCenter;
		bool centered;
		bool firstPoint;
		ofVec3f center;
};

#endif
