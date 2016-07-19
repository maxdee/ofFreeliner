#include "layer.h"

Layer::Layer(){

}

Layer* Layer::apply(Layer* _layer){
  // do nothing, pass the previous layer
  return _layer;
}

bool Layer::hasFbo(){
  return false;
}
////////////////////////////////////////////// output to screen layer

OutputLayer::OutputLayer(){}
// draws
Layer* OutputLayer::apply(Layer* _layer){
  if(_layer == nullptr) return nullptr;
  else if((*_layer).hasFbo()){
    (dynamic_cast<FboLayer*>(_layer))->draw();
  }
  return nullptr;
}

////////////////////////////////////////////// simple fbo layer

FboLayer::FboLayer(){
  fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight(), GL_RGBA);
  fbo.begin();
  ofClear(255,255,255, 0);
  fbo.end();
}

bool FboLayer::hasFbo(){
  return true;
}

Layer* FboLayer::apply(Layer* _layer){
  if(_layer == nullptr) return this;
  else if((*_layer).hasFbo()){
    FboLayer _f = *(dynamic_cast<FboLayer*>(_layer));
    _f.begin();
    fbo.draw(0,0);
    _f.end();
    return _layer;
  }
  else return this;
}

void FboLayer::initFrame(){
  fbo.begin();
  ofClear(255,255,255,0);
  fbo.end();
}

void FboLayer::begin(){
  fbo.begin();
}

void FboLayer::end(){
  fbo.end();
}

void FboLayer::draw(){
  fbo.draw(0,0);
}

////////////////////////////////////////////// simple fbo layer

WobblyFboLayer::WobblyFboLayer(){
  fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight(), GL_RGBA);
  fbo.begin();
  ofClear(255,255,255, 0);
  fbo.end();
  shader.load("shaders/vert.vert", "shaders/frag.frag");
}

void WobblyFboLayer::initFrame(){
  fbo.begin();
  ofClear(255,255,255,0);
  fbo.end();
}

void WobblyFboLayer::begin(){
  fbo.begin();
  ofFill();
  ofSetColor(255);
  shader.begin();
  shader.setUniform1f("time", ofGetElapsedTimef());
}

void WobblyFboLayer::end(){
  shader.end();
  fbo.end();
}
