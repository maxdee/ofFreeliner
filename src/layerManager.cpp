#include "layerManager.h"

LayerManager::LayerManager(){
	Layer* _f = new FboLayer();

	fboLayerStack.push_back(static_cast<FboLayer*>(_f) );
	layerStack.push_back( _f );

	Layer* _o = new OutputLayer();
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

ofFbo* LayerManager::getFbo(int _i){
	int _index = 0;
	vector<FboLayer*>::iterator _lyr;
	for(_lyr = fboLayerStack.begin(); _lyr != fboLayerStack.end(); _lyr++) {
		if(_i == _index) return (*_lyr)->getFbo();
		_index++;
	}
	return nullptr;
}

void LayerManager::beginFbos(){
	vector<FboLayer*>::iterator _lyr;
	for(_lyr = fboLayerStack.begin(); _lyr != fboLayerStack.end(); _lyr++) {
		(*_lyr)->beginFbo();
	}
}
