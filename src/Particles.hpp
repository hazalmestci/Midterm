//
//  Particles.hpp
//  Midterm
//
//  Created by Hazal Mestci on 3/20/17.
//
//

#pragma once
#include "ofMain.h"


class Particle{
public:
    
    Particle();
    
    void init();
    void bounding();
    void draw();
    void update( vector<Particle> &particles, ofVec2f mousePos);
    
    
    //make them vectors because has more functionality
    ofVec2f cohesion(vector<Particle> &particles);
    ofVec2f separation(vector<Particle> &particles);
    ofVec2f allignment(vector<Particle> &particles);
    ofVec2f followMouse(ofVec2f mousePos);
    
    ofPoint pos;
    ofPoint vel;
    int radius;
    
    
};
