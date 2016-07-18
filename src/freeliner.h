#ifndef freeliner_h
#define freeliner_h

#include "ofMain.h"
#include "flPointGroup.h"
#include "flDecorator.h"
#include "flTools.h"
#include "flPoint.h"

class Freeliner {
	private:
		float version = 0.01;
		float lerp;
		int groupCount;
		int focusGroup;
		int prevFocusGroup;

		vector<PointGroup> pointGroups;

		ofVec3f cursor;

		bool shifted;
		bool ctrled;
		bool mouseEnabled;
		bool snapping;
		bool snapped;
		int snapDist;

		void addGroup();
		void cycleGroups();
		void mouseSnapping();
		void nudger(int _i);

		void gui();
		void decorate();
		char editKey;
		bool isMapped(char _k);
		string editThing;
		string valueGiven;
		bool valueBool(bool _b);
		int valueInt(int _i);
		map<char, string> keyMap;

		void numMaker(int _k);
		void makeNumber();
		string numberBuff;
		void numberDispatch(int _n);
		void escape();

		Decorator deco;

	public:
		Freeliner();

		void update();
		void draw();

		void keyPress(int _k);
		void keyRelease(int _k);
		void mouseMove(int _x, int _y);
		void mousePress(int _b);

		ofTrueTypeFont font;
};

#endif
