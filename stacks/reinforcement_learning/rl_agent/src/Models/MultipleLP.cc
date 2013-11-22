/*
 * MultipleLP.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: menie
 */

#include "MultipleLP.hh"

MultipleLP::MultipleLP(int id, int trainMode, int trainFreq, int m,
        float featPct, Random rng):
	id(id), mode(trainMode), freq(trainFreq), M(m),
	featPct(featPct), rng(rng) {

}

MultipleLP::~MultipleLP() {
	// TODO Auto-generated destructor stub
}

bool MultipleLP::trainInstance(classPair& instance) {
}

bool MultipleLP::trainInstances(std::vector<classPair>& instances) {
}

void MultipleLP::testInstance(const std::vector<float>& input,
		std::map<float, float>* retval) {
}

float MultipleLP::getConf(const std::vector<float>& input) {
}

MultipleLP* MultipleLP::getCopy() {
}


