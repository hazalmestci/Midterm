//
//  Particles.cpp
//  Midterm
//
//  Created by Hazal Mestci on 3/20/17.
//
//

#include "Particles.hpp"


Particle::Particle(){
    
    radius = 5;
   // radius = ofRandom(-6, 12);
   // radius = ofRandom(50, 100);
    
}

void Particle::init(){
    
    //defining the position and velocity of the particles
    pos = ofPoint(ofRandom(-ofGetWidth()/2, ofGetWidth()/2),ofRandom(-ofGetHeight()/2, ofGetHeight()/2));
    
    vel = ofPoint(ofRandom(-1, 1), ofRandom(-1, 1));
    
}

void Particle::bounding(){
    
    if(pos.y > ofGetHeight()/2 || pos.y < -ofGetHeight()/2){
        vel = -vel;
    }
    if(pos.x > ofGetWidth()/2 || pos.x < -ofGetWidth()/2){
        vel = -vel;
    }
}


void Particle::draw(){
    
//    radius = ofRandom(50, 100);
    ofCircle(pos.x, pos.y, radius);
    

}


ofVec2f Particle::cohesion(vector<Particle> &particles){
    
    
    ofPoint centerMass;
    for(int i = 0; i < particles.size(); i++){
        //to make one particle to avoid itself
        if (&particles[i] == this) {
            continue;
        }
        
        centerMass += particles[i].pos;
        
    }
    
    centerMass = centerMass/(particles.size()-150);
    
    ofPoint cohesion_velocity;
    cohesion_velocity = (centerMass-pos)/200.0f;
    return cohesion_velocity;
    
}

ofVec2f Particle::followMouse(ofVec2f mousePos){
    
    ofPoint cohesion_velocity;
    cohesion_velocity = (mousePos-pos)/200.0f;
    
    //  cout << cohesion_velocity << endl;
    return cohesion_velocity;
    
    
    ofPoint (desiredVel) = ofPoint (mousePos - this->pos);
    ofPoint (steer) = ofPoint (desiredVel - this->vel);
    return steer;
    
    
}

ofVec2f Particle::separation(vector<Particle> &particles){
    
    ofPoint displace;
    for(int i = 0; i < particles.size(); i++){
        
        if (&particles[i] == this) {
            continue;
        }
        
        // distance between me and particles[i]
        float dist = pow(particles[i].pos.x - pos.x, 5) + pow(particles[i].pos.y - pos.y, 5);
        dist = sqrt(dist);
        
        if (dist < 50.0) {
            displace  = displace - (particles[i].pos - pos);
        }
        
    }
    
    ofPoint separation_velocity;
    separation_velocity = displace;
    return separation_velocity;
}

ofVec2f Particle::allignment(vector<Particle> &particles){
    
    ofPoint aveVel;
    for(int i = 0; i < particles.size(); i++){
        //checking if the particle in the loop is itself
        if (&particles[i] == this) {
            continue;
        }
        
        aveVel += particles[i].vel;
    }
    
    aveVel = aveVel/(particles.size()-1);
    
    ofPoint allignment_velocity;
    allignment_velocity = (aveVel - vel)/12.0f;
    return allignment_velocity;
    
}

void Particle:: update( vector<Particle> &particles, ofVec2f mousePos ){
    
    ofPoint v0 = followMouse(mousePos);
    ofPoint v1 = cohesion(particles);
    ofPoint v2 = separation(particles);
    ofPoint v3 = allignment(particles);
    
    //    cout << v0 << endl;
    
    vel += v0 + v1 + v2 + v3;
    pos = pos + vel;
    
}
