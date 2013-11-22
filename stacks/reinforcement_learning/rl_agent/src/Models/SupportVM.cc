/*
 * SupportVM.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: menie
 */

#include "SupportVM.hh"

SupportVM::SupportVM(int id, int trainMode, int trainFreq, int m,
        float featPct, Random rng):
	id(id), mode(trainMode), freq(trainFreq), M(m),
	featPct(featPct), rng(rng) {

	params.svm_type    = CvSVM::C_SVC;
    params.kernel_type = CvSVM::LINEAR;
}

SupportVM::~SupportVM() {

}

bool SupportVM::trainInstance(classPair& instance) {

}

bool SupportVM::trainInstances(std::vector<classPair>& instances) {
	float** trainingData;
	float* labels;

	trainingData = new float*[instances.size()];
	labels = new float[instances.size()];

	for(std::vector<classPair>::iterator it = instances.begin(); it != instances.end(); ++it) {
		int index = it - instances.begin();
		trainingData[index] = &(*it).in[0];
		labels[index] = (*it).out;
	}
}

void SupportVM::testInstance(const std::vector<float>& input,
		std::map<float, float>* retval) {
}

float SupportVM::getConf(const std::vector<float>& input) {
}

SupportVM* SupportVM::getCopy() {
}
