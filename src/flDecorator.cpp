#include "flDecorator.h"

Decorator::Decorator(){
	fluct = 0;
	style.color = ofColor(255);
	style.bgColor = ofFloatColor(0,0,1);
	style.smoothing = false;
	style.lineWidth = 1;

}

void Decorator::decorate(FboLayer* _layer, PointGroup _pg, float _f){
	if(_layer == nullptr) return;
	_layer->begin();

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
			mush.addColor(ofFloatColor(sin(arpos),0,arpos));
			mush.addVertex(_pg.segments[i].getPointB());
			mush.addColor(ofFloatColor(sin(arpos),0,-arpos+1));

			//ofLine(_pg.segments[i].getPointA(), _pg.segments[i].getPointB());
		}

		mush.draw(OF_MESH_FILL);//WIREFRAME);
		mush.drawFaces();
	}

	_layer->end();
}
