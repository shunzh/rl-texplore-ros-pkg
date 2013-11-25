/*
 * MultipleLP.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: Shun Zhang
 */

#include "MultipleLP.hh"

using namespace cv;

MultipleLP::MultipleLP(int id, int trainMode, int trainFreq, int m,
        float featPct, Random rng):
	id(id), mode(trainMode), freq(trainFreq), M(m),
	featPct(featPct), rng(rng) {

	pthread_mutex_init(&mlp_mutex, NULL);
}

MultipleLP::~MultipleLP() {
	// TODO Auto-generated destructor stub
}

bool MultipleLP::trainInstance(classPair& instance) {
	std::vector<classPair> vec;
	vec.push_back(instance);
	return trainInstances(vec);
}

bool MultipleLP::trainInstances(std::vector<classPair>& instances) {

}

void MultipleLP::testInstance(const std::vector<float>& input,
		std::map<float, float>* retval) {

}

float MultipleLP::getConf(const std::vector<float>& input) {
	// FIXME dummy
	return 1;
}

MultipleLP* MultipleLP::getCopy() {
	return new MultipleLP(*this);
}
