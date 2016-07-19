#ifndef layerManager_h
#define layerManager_h

#include "ofMain.h"
#include "layer.h"


class LayerManager {
	private:
		vector<Layer*> layerStack;
		// vector<FboLayer*> fboLayerStack;

		//second pos?

	public:
		LayerManager();
		void render();
		FboLayer* getFboLayer(int);
		void initFrames();
};

#endif
