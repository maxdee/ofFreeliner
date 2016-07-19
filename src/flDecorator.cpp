#include "flDecorator.h"

Decorator::Decorator(){
	fluct = 0;
	style.color = ofColor(255);
	style.bgColor = ofFloatColor(0,0,1);
	style.smoothing = false;
	style.lineWidth = 1;

	shader.load("shaders/vert.vert", "shaders/frag.frag");

}

void Decorator::decorate(ofFbo _fbo, PointGroup _pg, float _f){
	_fbo.begin();

	shader.begin();
	shader.setUniform1f("time", ofGetElapsedTimef());

	ofSetStyle(style);

	if(_pg.segCount > 0){
		fluct += 0.01;
		ofVec3f pA;
		ofVec3f pB;
		ofMesh mush = ofMesh();
		mush.setMode(OF_PRIMITIVE_LINES );
		for(int i = 0; i < _pg.segCount; i++) {
			float arpos = float(i)/_pg.segCount;

			mush.addVertex(_pg.segments[i].getPointA());
			mush.addColor(ofColor(255,0,0));//ofFloatColor(sin(arpos),0,arpos));
			mush.addVertex(_pg.segments[i].getPointB());
			mush.addColor(ofColor(255,0,0));//ofFloatColor(sin(arpos),0,-arpos+1));

			//ofLine(_pg.segments[i].getPointA(), _pg.segments[i].getPointB());
		}

		mush.draw(OF_MESH_FILL);//WIREFRAME);
		mush.drawFaces();
	}
	shader.end();
	_fbo.end();
}
