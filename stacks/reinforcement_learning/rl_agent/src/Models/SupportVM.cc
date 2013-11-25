/*
 * SupportVM.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: menie
 */

#include "SupportVM.hh"

using namespace cv;

SupportVM::SupportVM(int id, int trainMode, int trainFreq, int m,
        float featPct, Random rng):
	id(id), mode(trainMode), freq(trainFreq), M(m),
	featPct(featPct), rng(rng) {

	pthread_mutex_init(&svm_mutex, NULL);
}

SupportVM::~SupportVM() {
}

bool SupportVM::trainInstance(classPair& instance) {
	std::vector<classPair> vec;
	vec.push_back(instance);
	return trainInstances(vec);
}

bool SupportVM::trainInstances(std::vector<classPair>& instances) {

}

void SupportVM::testInstance(const std::vector<float>& input,
		std::map<float, float>* retval) {

}

float SupportVM::getConf(const std::vector<float>& input) {
	// FIXME trivial
	return 1;
}

SupportVM* SupportVM::getCopy() {
	SupportVM* svm = new SupportVM(*this);
	return svm;
}
