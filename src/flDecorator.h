#ifndef decorator_h
#define decorator_h

#include "ofMain.h"
#include "flPointGroup.h"
#include "flTools.h"

class Decorator {
	private:
		ofStyle style;
		float fluct;
		ofShader shader;

	public:
		Decorator();

		void decorate(PointGroup _pg, float _f);
};

#endif