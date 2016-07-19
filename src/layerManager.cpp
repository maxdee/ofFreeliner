#include "layerManager.h"

LayerManager::LayerManager(){
	Layer* _o = new OutputLayer();

	layerStack.push_back( new FboLayer() );
	layerStack.push_back( _o );

	layerStack.push_back( new WobblyFboLayer() );
	layerStack.push_back( _o );
}

void LayerManager::render(){
	Layer* _prevLayer = nullptr;
	vector<Layer*>::iterator _lyr;
	for(_lyr = layerStack.begin(); _lyr != layerStack.end(); _lyr++) {
		(*_lyr)->apply(_prevLayer);
		_prevLayer = (*_lyr);
	}
}

FboLayer* LayerManager::getFboLayer(int _i){
	int _index = 0;
	_i %= 2;
	vector<Layer*>::iterator _lyr;
	for(_lyr = layerStack.begin(); _lyr != layerStack.end(); _lyr++) {
		if((*_lyr)->hasFbo()){
			if(_index == _i) return dynamic_cast<FboLayer*>(*_lyr);
			_index++;
		}
	}
	return nullptr;
	// return fboLayerStack[_i % fboLayerStack.size()];
}

void LayerManager::initFrames(){
	vector<Layer*>::iterator _lyr;
	for(_lyr = layerStack.begin(); _lyr != layerStack.end(); _lyr++) {
		if((*_lyr)->hasFbo()){
			(dynamic_cast<FboLayer*>(*_lyr))->initFrame();
		}
	}
}
