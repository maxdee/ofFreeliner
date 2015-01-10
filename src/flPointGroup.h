#ifndef flPointGroup_h
#define flPointGroup_h

#include "ofMain.h"
#include "flSegment.h"
#include "flTools.h"

class PointGroup {
	private:
	

		void startSegment(ofVec2f _p);
		void endSegment(ofVec2f _p);
		void placeCenter(ofVec2f _p);
		void unCenter();
		void undo();
	public:
		PointGroup();
		void init(int &_id);
		//~PointGroup();

		void mousePress(int _b, ofVec2f _p);
		void keyPress(int _k);
		void gui(ofVec2f _p, ofTrueTypeFont _tt);
		void decorate(float _f);

		void snapNudge(float _d, ofVec2f _p, ofVec2f _n);
		void nudgeLast(ofVec2f _n);
		ofVec2f findNear(float _d, ofVec2f _p);

		//////////// was private
		ofVec2f previousPos;
		int ident;
		int segCount;
		int polka;
		float fluct;
		vector<Segment> segments;
		bool putCenter;
		bool centered;
		bool firstPoint;
		ofVec2f center;
};

#endif