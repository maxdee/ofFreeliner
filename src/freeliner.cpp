
#include "freeliner.h"
#include "flTools.h"

Freeliner::Freeliner(){
	cout << "alc's ofFreeliner version : " << version << endl;
	focusGroup = -1;
	groupCount = 0;
	shifted = false;
	ctrled = false;
	lerp = 0.0;
	font.loadFont("arial.ttf", 14);

	mouseEnabled = true;
	snapping = true;
	snapped = false;
	snapDist = 24;

	keyMap['.'] = "snapping";
	keyMap['c'] = "placeCenter";
	keyMap['t'] = "tapTempo";
	keyMap['n'] = "newGroup";

}


void Freeliner::update(){
	lerp += 0.01;
}

void Freeliner::draw(){
	ofBackground(0);
	decorate();
	gui();
}

//////////////////////////////////////////////////////////////////////////////
///////////// Point Group management 
//////////////////////////////////////////////////////////////////////////////

void Freeliner::addGroup(){
	pointGroups.push_back( PointGroup() );
	groupCount = pointGroups.size()-1;
	focusGroup = groupCount;
	pointGroups[focusGroup].init(groupCount);
}

void Freeliner::cycleGroups(){
	if(shifted) focusGroup--;
	else focusGroup++;
	focusGroup = wrap(focusGroup, groupCount);
	cout << "freeliner.cpp: focus cycle to :  " << focusGroup << endl;
}


void Freeliner::decorate(){
	vector<PointGroup>::iterator this_group;
	for(this_group = pointGroups.begin(); this_group != pointGroups.end(); this_group++) {
		this_group->decorate(lerp);
	}
}

void Freeliner::mouseSnapping(){
	ofVec2f tmp;
	tmp.set(0,0);
	
	vector<PointGroup>::iterator this_group;
	for(this_group = pointGroups.begin(); this_group != pointGroups.end(); this_group++) {
		tmp.set(this_group->findNear(snapDist, cursor));
		if(tmp.x != -1) break;
	}
	
	if(tmp.x != -1){
		cursor.set(tmp);
		snapped = true;
	}
	else snapped = false;
}


void Freeliner::nudger(int _i){
	ofVec2f dir;
	if(_i == 0) dir.set(0,-1);
	else if(_i == 1) dir.set(0,1);
	else if(_i == 2) dir.set(-1,0);
	else if(_i == 3) dir.set(1,0);
	if(shifted) dir*=20;
	if(snapped){
		ofVec2f tmp;
		vector<PointGroup>::iterator this_group;
		for(this_group = pointGroups.begin(); this_group != pointGroups.end(); this_group++) {
			this_group->snapNudge(snapDist, cursor, dir);
		}
		cursor += dir;
	}
	else if(focusGroup != -1){
		if(focusGroup > -1){
			pointGroups[focusGroup].nudgeLast(dir);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
///////////// User input
//////////////////////////////////////////////////////////////////////////////

void Freeliner::keyPress(int _k){
	//cout << "Key pressed " << _k << endl;
	//distribute key to group
	if(focusGroup > -1){
		pointGroups[focusGroup].keyPress(_k);
	}
	//first the non-ascii keys
	if(_k == 9) cycleGroups();
	else if(_k == 2305) shifted = true;
	else if(_k == 769) ctrled = true;
	else if(_k == 357) nudger(0);
	else if(_k == 359) nudger(1);
	else if(_k == 356) nudger(2);
	else if(_k == 358) nudger(3);
	else if(isMapped(_k)){
		if(_k == 'n') addGroup();
		else if(_k == '.') snapping = valueBool(!snapping);
		else editKey = _k;
	}
	else cout << "freeliner.cpp: not mapped? " << char(_k) << endl;
	//cout << editThing << ' ' << valueGiven << endl;
}

bool Freeliner::isMapped(char _k){
	if(keyMap.count(_k)>0){
		editThing = keyMap[_k];
		return true;
	}
	else return false;
}

void Freeliner::keyRelease(int _k){
	if(_k == 2305) shifted = false;
	else if(_k == 769) ctrled = false;
	//cout << "freeliner.cpp: released :  " << _k << endl;
}

void Freeliner::mouseMove(int _x, int _y){
	if(mouseEnabled){
		cursor.set(_x, _y);
		if(snapping) mouseSnapping();

	}
}

void Freeliner::mousePress(int _b){
	if(focusGroup > -1){
		pointGroups[focusGroup].mousePress(_b, cursor);
	}
}

//////////////////////////////////////////////////////////////////////////////
///////////// user input feedback
//////////////////////////////////////////////////////////////////////////////

bool Freeliner::valueBool(bool _b){
	if(_b)valueGiven = "true";
	else valueGiven = "false";
	return _b;
}

int Freeliner::valueInt(int _i){
	valueGiven = ofToString(_i);
	return _i;
}

//////////////////////////////////////////////////////////////////////////////
///////////// gui 
//////////////////////////////////////////////////////////////////////////////

void Freeliner::gui(){
	if(snapped) ofSetColor(0,255,0);
	else ofSetColor(255,0,0);
	//ofFill();
	ofCircle(cursor.x, cursor.y, 5);
	if(focusGroup > -1){
		pointGroups[focusGroup].gui(cursor, font);
	}
	ofSetColor(255);
	font.drawString(ofToString(ofGetFrameRate()), 10, 30);
	font.drawString((editThing + valueGiven), 10, 50);
}