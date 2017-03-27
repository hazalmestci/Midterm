#pragma once

#include "ofMain.h"
#include "Particles.hpp"
#include "ofxBox2d.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
  //  void mouseEntered(int x, int y);
  //  void mouseExited(int x, int y);

    ofxBox2d                                 box2d;
    vector     <shared_ptr<ofxBox2dCircle> > circles;
    vector     <shared_ptr<ofxBox2dRect> >   boxes;   
    
    
    vector<Particle> flockingParticles;
    
    int num;
    
    ofImage sky;
    
};
