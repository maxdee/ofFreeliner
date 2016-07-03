#include "ofMain.h"
//#include "ofAppGlutWindow.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofAppGlutWindow window;
	//ofSetupOpenGL(&window, 2000, 2000, OF_GAME_MODE);// OF_WINDOW);//OF_FULLSCREEN);			// <-------- setup the GL context
	//window.hideCursor();
	//window.setWindowTitle("alcFreeliner - OF edition");
	ofSetLogLevel(OF_LOG_VERBOSE);
	#ifdef TARGET_OPENGLES
    	ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);
	#endif

	ofSetupOpenGL(1024, 768, OF_WINDOW);//OF_FULLSCREEN);
	ofHideCursor();
	ofSetWindowTitle("alcFreeliner - OF edition");
	ofSetEscapeQuitsApp(false);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
