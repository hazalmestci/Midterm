#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
   // ofBackground(0);
    //  ofSetBackgroundAuto(false);
    
    //create the particles
    num = 500;
    
    for(int i =0; i < num; i++){
        
        Particle p;
        flockingParticles.push_back(p);
        flockingParticles[i].init();
        
    }
    
    //box2d
    ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_NOTICE);
    ofDisableAntiAliasing();
    
    box2d.init();
    box2d.setGravity(0, 0);
    box2d.setFPS(60.0);
    box2d.createBounds();
    
    
    sky.load("sky.jpg");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
   ofPoint Mouse= ofPoint (mouseX, mouseY);
    
    cout << Mouse << endl;
    
    for(int i = 0; i < num; i++){
        
        flockingParticles[i].update(flockingParticles, Mouse);
        flockingParticles[i].bounding();
        
    }
    
    //box2d
    box2d.update();
    ofVec2f mouse(ofGetMouseX(), ofGetMouseY());
    bool isAttracted = ofGetMousePressed() ? true : false;
    
    for(int i=0; i<boxes.size(); i++) {
        float dis = mouse.distance(boxes[i].get()->getPosition());
        
        if(isAttracted == true){
            boxes[i].get()->addAttractionPoint(mouse, 4.0);
        }else {
            box2d.setGravity(0, 10);
        }
        
    }
    
    for(int i=0; i<circles.size(); i++) {
        float dis = mouse.distance(circles[i].get()->getPosition());
        
        if(isAttracted == true){
            circles[i].get()->addAttractionPoint(mouse, 4.0);
        }else {
            box2d.setGravity(0, 10);
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
   sky.draw(0, 0);
    
    //box2d
    for(int i=0; i<boxes.size(); i++) {
        ofSetColor(2,59,91);
        boxes[i].get()->draw();
    }
    
    for(int i=0; i<circles.size(); i++) {
        ofSetColor(27, 51, 7);
        circles[i].get()->draw();
    }

    
    // ofBackground(0);
    //ofSetColor(ofRandom(10,20),ofRandom(10,20),ofRandom(255),ofRandom(170));
    
    ofSetColor(229, 229, 208);
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    for(int i = 0; i < num; i++){
        flockingParticles[i].draw();
    }
  
    
    string info = "";
    info += "Press [s] for filling the sea\n";
    info += "Press [m] for filling the mountain\n";
  //  ofSetHexColor(0x444342);
    ofDrawBitmapString(info, 0, 0);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //box2d
    
    if(key == 's') {
        float w = ofRandom(30, 50);
        float h = ofRandom(30, 50);
        shared_ptr<ofxBox2dRect> rect = shared_ptr<ofxBox2dRect>(new ofxBox2dRect);
        rect.get()->setPhysics(3.0, 0.53, 0.9);
        rect.get()->setup(box2d.getWorld(), mouseX, mouseY, w, h);
        boxes.push_back(rect);
    }
    
    if(key == 'm') {
      	float r = ofRandom(24, 30);
        shared_ptr<ofxBox2dCircle> circle = shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle);
        circle.get()->setPhysics(3.0, 0.53, 0.9);
        circle.get()->setup(box2d.getWorld(), mouseX, mouseY, r);
        circles.push_back(circle);
    }
    
}



//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
