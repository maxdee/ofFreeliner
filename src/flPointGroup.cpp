
#include "flPointGroup.h"


PointGroup::PointGroup(){

}

void PointGroup::init(int &_id){
	ident = _id;
	//cout << "PointGrousp.cpp: New group: " << ident << endl;
	putCenter = false;
	centered = false;
	firstPoint = true;
	segCount = 0;
	polka = 3;
	fluct = 0.0;
}

// PointGroup::~PointGroup(){
// 	cout << "PointGroup.cpp: REMOVED group: " << ident << endl;
// }

//////////////////////////////////////////////////////////////////////////////
///////////// Passed input
//////////////////////////////////////////////////////////////////////////////

void PointGroup::mousePress(int _b, ofVec3f _p){

	if (_b == 0 && putCenter) placeCenter(_p);
    else if (_b == 2 && putCenter) unCenter();
    else if (_b == 0 && firstPoint) startSegment(_p);
    else if (_b == 0 && !firstPoint) endSegment(_p);
    else if (_b == 2) undo();
    else if (_b == 1) startSegment(_p);  //breakSegment(p);
    //else if (b == 4) trackball extra buttons!
   	//else if (b == 5)
}

void PointGroup::keyPress(int _k){
	if(_k == 'c') putCenter = true;
}



//////////////////////////////////////////////////////////////////////////////
///////////// Point Group Management
//////////////////////////////////////////////////////////////////////////////

void PointGroup::startSegment(ofVec3f _p){
	previousPos = _p;
	firstPoint = false;
}

void PointGroup::endSegment(ofVec3f _p){
	segments.push_back( Segment(previousPos, _p) );
	segCount++;
	previousPos = _p;
}

void PointGroup::placeCenter(ofVec3f _p){
	cout << "PointGroup :" << segments.size() << endl;
	center = _p;
	centered = true;
	putCenter = false;
}

void PointGroup::unCenter(){
	centered = false;
}

void PointGroup::undo(){
	if(segCount > 0){
		segCount--;
		if(segCount < 1){
			previousPos.set(segments[segCount].getPointA());
		}
		else previousPos.set(segments[segCount-1].getPointB());
		segments.erase(segments.end());
	}
	else if(firstPoint){
		centered = false;
	}
	else{
		firstPoint = true;
		previousPos.set(0,0,0);
	}

}

ofVec3f PointGroup::findNear(float _d, ofVec3f _p){
	vector<Segment>::iterator this_seg;
	for(this_seg = segments.begin(); this_seg != segments.end(); this_seg++) {
		if(this_seg->pointA.checkProx(_d, _p)) return this_seg->pointA.get();
		else if(this_seg->pointB.checkProx(_d, _p)) return this_seg->pointB.get();
	}
	return ofVec3f(-1,-1);
}

void PointGroup::snapNudge(float _d, ofVec3f _p, ofVec3f _n){
	vector<Segment>::iterator this_seg;
	for(this_seg = segments.begin(); this_seg != segments.end(); this_seg++) {
		if(this_seg->pointA.checkProx(_d, _p)) this_seg->pointA.nudge(_n);
		else if(this_seg->pointB.checkProx(_d, _p)) this_seg->pointB.nudge(_n);
	}
}

void PointGroup::nudgeLast(ofVec3f _n){
	previousPos += _n;
	segments[segCount-1].pointB.nudge(_n);
}
//////////////////////////////////////////////////////////////////////////////
///////////// gui and stuff
//////////////////////////////////////////////////////////////////////////////

void PointGroup::gui(ofVec3f _p, ofTrueTypeFont _tt){
	ofPushStyle();
	glLineWidth(1);
	ofNoFill();
	ofSetColor(100);
	vector<Segment>::iterator this_seg;
	for(this_seg = segments.begin(); this_seg != segments.end(); this_seg++) {
		this_seg->show();
	}
	if(previousPos.x > 0.1){
		glLineWidth(3);
		ofNoFill();
		ofSetColor(255);
		ofLine(_p, previousPos);
	}

	ofSetColor(255);
	ofVec3f tag;
	if(centered) tag = center;
	else if(segCount > 0) tag = segments[0].getPointA();
	else if(!firstPoint) tag = previousPos;
	else tag = _p;

	glLineWidth(1);
	ofCircle(tag.x, tag.y, 10);
	_tt.drawString(ofToString(ident), tag.x-(25+(ident>9)*12), tag.y+7);
	ofPopStyle();
}



void PointGroup::decorate(float _f){
	// if(segCount > 0){
	// 	fluct += 0.01;
	// 	fluct = floatWrap(fluct);
	// 	glLineWidth(2);
	// 	ofEnableAntiAliasing();
	// 	ofEnableSmoothing();
	// 	ofVec3f pA;
	// 	ofVec3f pB;
	// 	for(int i = 0; i <= segCount; i++) {
	// 		pA.set(segments[i].getPointA());
	// 		pB.set(segments[i].getPointB());

	// 		ofNoFill();
	// 		ofSetColor(255);
	// 		for(int j = 0; j < 100; j++){
	// 			float f = float(j)/100;
	// 			ofSetColor(ofFloatColor(abs(sin(f+fluct)), cos(f-fluct), abs(tan(f-fluct))));
	// 			pA.interpolate(center, floatWrap(f+fluct));
	// 			pB.interpolate(center, floatWrap(f+fluct));
	// 			ofLine(pA.getRotated(sin(f)*360, center), pB.getRotated(cos(f)*360, center));
	// 			//cout << pA << endl;
	// 		}

	// 	}
	// }
}


	// if(segCount >= 0){
	// 	fluct += 0.001;
	// 	fluct = floatWrap(fluct);
	// 	glLineWidth(1);
	// 	for(int i = 0; i <= segCount; i++) {
	// 		int ranA = i;
	// 		int ranB = (i+3)%segCount;
	// 		ofNoFill();
	// 		for(int j = 0; j < 10; j++){
	// 			float f = float(j)/10;
	// 			ofSetColor(ofFloatColor(abs(sin(f+fluct)), cos(f-fluct), abs(tan(f-fluct))));
	// 			ofLine(segments[ranA].getLerp(floatWrap(f+fluct)), segments[ranB].getLerp(floatWrap(f+fluct)));
	// 		}

	// 	}
	// }


//glLineWidth
		// (2);
		// for(int i = 0; i < 2000; i++) {
		// 	int ranA = int(ofRandom(segCount));
		// 	int ranB = int(ofRandom(segCount));
		// 	ofNoFill();
		// 	ofSetColor(ofFloatColor(ofRandomuf(),ofRandomuf(),ofRandomuf()));
		// 	ofLine(segments[ranA].getLerp(ofRandomuf()), segments[ranB].getLerp(ofRandomuf()));
		// }





// void PointGroup::decorate(float _f){
// 	vector<Segment>::iterator this_seg;
// 	ofMesh shape;
// 	for(this_seg = segments.begin(); this_seg != segments.end(); this_seg++) {
// 		shape.addVertex(this_seg->getPointA());
// 		shape.addColor(ofFloatColor(1,1,1));
// 		shape.addVertex(this_seg->getPointB());
// 		shape.addColor(ofFloatColor(0,0,0));
// 	}
// 	shape.draw();
// 	shape.drawWireframe();

// }
