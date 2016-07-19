#include "layer.h"

Layer::Layer(){

}

Layer* Layer::apply(Layer* _layer){
  // do nothing, pass the previous layer
  return _layer;
}

ofFbo* Layer::getFbo(){
  return nullptr;
}
void Layer::beginFbo(){}
////////////////////////////////////////////// output to screen layer

OutputLayer::OutputLayer(){}

Layer* OutputLayer::apply(Layer* _layer){
  if(_layer == nullptr) return this;
  if(_layer->getFbo() != nullptr){
    ofFbo _f = *(_layer->getFbo());
    _f.draw(0,0);
  }
  return nullptr;
}

ofFbo* OutputLayer::getFbo(){
  return nullptr;
}
void OutputLayer::beginFbo(){}

////////////////////////////////////////////// simple fbo layer

FboLayer::FboLayer(){
  fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight(), GL_RGBA);
  fbo.begin();
  ofClear(255,255,255, 0);
  fbo.end();
}

Layer* FboLayer::apply(Layer* _layer){
  if(_layer == nullptr) return this;
  else if(_layer->getFbo() != nullptr){
    ofFbo _f = *(_layer->getFbo());
    _f.begin();
    fbo.draw(0,0);
    _f.end();
    return _layer;
  }
  else return this;
}

ofFbo* FboLayer::getFbo(){
  return &fbo;
}

// call pre rendering
void FboLayer::beginFbo(){
  fbo.begin();
  ofClear(255,255,255,0);
  fbo.end();
}

/////////////////////////////////////////////
