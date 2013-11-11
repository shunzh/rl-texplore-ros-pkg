/*
 * Asterix.cc
 *
 *  Created on: Nov 10, 2013
 *      Author: menie
 */

#include "Asterix.hh"

Asterix::Asterix(Random &rand, bool extraVariation, bool stoch):
	height(6), width(10),
	goal(coord_t(5,5)),
	extraVar(extraVariation),
	noisy(stoch),
	rng(rand)
{

}

Asterix::~Asterix() {
}

const std::vector<float> &Asterix::sensation() const {
}

float Asterix::apply(int action) {

}

bool Asterix::terminal() const {

}

void Asterix::reset() {

}

int Asterix::getNumActions() {

}

void getMinMaxFeatures(std::vector<float> *minFeat, std::vector<float> *maxFeat) {

}

void getMinMaxReward(float* minR, float* maxR) {

}

std::vector<experience> getSeedings() {

}
