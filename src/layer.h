#ifndef layer_h
#define layer_h

#include "ofMain.h"

class Layer {
	private:

	public:
		Layer();
    virtual Layer* apply(Layer* _layer);
		virtual bool hasFbo();
};

/////////////////////////////////////

class OutputLayer : public Layer {
	private:

	public:
		OutputLayer();
		virtual Layer* apply(Layer* _layer) override;
};

/////////////////////////////////////

class FboLayer : public Layer {
	private:
	public:
		ofFbo fbo;
		FboLayer();
		bool hasFbo() override;
		virtual Layer* apply(Layer* _layer) override;
		virtual void begin();
		virtual void end();
		virtual void initFrame();
		virtual void draw();
};

/////////////////////////////////////

class WobblyFboLayer : public FboLayer {
	private:
		ofShader shader;
	public:
		WobblyFboLayer();
		virtual void begin() override;
		virtual void end() override;
		virtual void initFrame() override;
};

#endif
