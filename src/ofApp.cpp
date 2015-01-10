#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	freeLiner = Freeliner();
}

//--------------------------------------------------------------
void ofApp::update(){
	freeLiner.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	freeLiner.draw();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	freeLiner.keyPress(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	freeLiner.keyRelease(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	freeLiner.mouseMove(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	freeLiner.mousePress(button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
