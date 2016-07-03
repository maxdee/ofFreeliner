#include "flDecorator.h"

Decorator::Decorator(){
	fluct = 0;
	style.color = ofColor(255);
	style.bgColor = ofFloatColor(0,0,1);
	style.smoothing = false;
	style.lineWidth = 1;

	// #ifdef TARGET_OPENGLES
	// 	shader.load("shaders_gles/noise.vert","shaders_gles/noise.frag");
	// #else
	// 	// if(ofGetGLProgrammableRenderer()){
	// 	shader.load("shaders_gl3/noise.vert", "shaders_gl3/noise.frag");
	// 	// }else{
	// 	// 	shader.load("shaders/noise.vert", "shaders/noise.frag");
	// 	// }
	// #endif
}

void Decorator::decorate(PointGroup _pg, float _f){
	// shader.begin();
	ofSetStyle(style);
	if(_pg.segCount > 0){
		fluct += 0.01;
		ofVec2f pA;
		ofVec2f pB;
		ofMesh mush = ofMesh();
		mush.setMode(OF_PRIMITIVE_LINES );
		for(int i = 0; i < _pg.segCount; i++) {
			float arpos = float(i)/_pg.segCount;

			mush.addVertex(vec2to3(_pg.segments[i].getPointA()));
			mush.addColor(ofColor(255));//ofFloatColor(sin(arpos),0,arpos));
			mush.addVertex(vec2to3(_pg.segments[i].getPointB()));
			mush.addColor(ofColor(255));//ofFloatColor(sin(arpos),0,-arpos+1));

			//ofLine(_pg.segments[i].getPointA(), _pg.segments[i].getPointB());
		}

		mush.draw(OF_MESH_FILL);//WIREFRAME);
		//mush.drawFaces();
	}
	// shader.end();
}
