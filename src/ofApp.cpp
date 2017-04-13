#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Limit drawing to a sane rate
    ofSetVerticalSync(true);

    //some path, may be absolute or relative to bin/data
    string path = "movies";
    ofDirectory dir(path);
    //only show png files
    dir.allowExt("mov");
    //populate the directory object
    dir.listDir();
    
    //go through and print out all the paths
    if ((int)dir.size() != VIDEO_NUMBER){
        cout << "please put 24 of hap videos!" << endl;
    }else {
        for(int i = 0; i < (int)dir.size(); i++){
            players[i].load(dir.getPath(i));
            players[i].play();
            players[i].setVolume(0);
            ofLogNotice(dir.getPath(i));
        }
    }
    
    drawingVideoId = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    players[drawingVideoId].update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    players[drawingVideoId].draw(0, 0);
    
    // debug
    ofDrawBitmapString("FPS:" + ofToString(ofGetFrameRate(), 0), 20, 20);
    ofDrawBitmapString("VIDEO ID:" + ofToString(drawingVideoId, 0), 20, 40);
}

void ofApp::drawAllPlayers(){
    for (int i = 0; i < VIDEO_NUMBER; i++){
        if (players[i].isLoaded()){
            ofSetColor(255, 255, 255);
            players[i].draw(20+i%6*100, 30 + i/6*100, 80, 60);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    drawingVideoId ++;
    if(drawingVideoId >= VIDEO_NUMBER){
        drawingVideoId = 0;
    }else{
        players[drawingVideoId].setFrame(players[0].getCurrentFrame());
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
