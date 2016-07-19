#ifndef layer_h
#define layer_h

#include "ofMain.h"

class Layer {
	private:

	public:
		Layer();
    virtual Layer* apply(Layer* _layer);
		virtual ofFbo* getFbo();
		virtual void beginFbo();
};
/////////////////////////////////////

class OutputLayer : public Layer {
	private:

	public:
		OutputLayer();
		virtual Layer* apply(Layer* _layer);
		virtual ofFbo* getFbo();
		virtual void beginFbo();
};

/////////////////////////////////////

class FboLayer : public Layer {
	private:
    ofFbo fbo;

	public:
		FboLayer();
		virtual Layer* apply(Layer* _layer);
		virtual ofFbo* getFbo();
		virtual void beginFbo();
};

#endif
