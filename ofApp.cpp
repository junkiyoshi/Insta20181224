#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum());

	for (int x = -150; x <= 150; x += 150) {

		for (int y = -150; y <= 150; y += 150) {

			this->drawNoiseBox(glm::vec3(x, y, 0), 100);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::drawNoiseBox(glm::vec3 location, int length) {

	ofPushMatrix();
	ofTranslate(location);

	int size = 20;
	for (int x = -length * 0.5; x <= length * 0.5; x += size) {

		for (int y = -length * 0.5; y <= length * 0.5; y += size) {

			for (int z = -length * 0.5; z <= length * 0.5; z += size) {

				glm::vec3 box_location = glm::vec3(x, y, z);
				float noise_value = ofNoise(location.x + x * 0.005, location.y + y * 0.005, location.z + z * 0.005, ofGetFrameNum() * 0.02);

				if (noise_value > 0.5) {

					ofFill();
					ofSetColor(39);
					ofDrawBox(box_location, size - 2);

					ofSetColor(239);
					ofNoFill();
					ofDrawBox(box_location, size - 1);
				}
			}
		}
	}

	ofPopMatrix();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}