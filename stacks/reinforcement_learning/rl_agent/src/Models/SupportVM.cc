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
}

SupportVM::~SupportVM() {

}

bool SupportVM::trainInstance(classPair& instance) {
	std::cerr << "SupportVM: trainInstance called." << std::endl;
	return false;
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

	Mat trainingMat(instances.size(), instances[0].in.size(), CV_32FC1, trainingData);
	Mat labelMat(instances.size(), 1, CV_32FC1, labels);

	SVM.train(trainingMat, labelMat);

	return true;
}

void SupportVM::testInstance(const std::vector<float>& input,
		std::map<float, float>* retval) {
	float* testData = &input[0];

	float predit = SVM.predict(testData, false);

	retval[predit] = 1;
}

float SupportVM::getConf(const std::vector<float>& input) {
	// FIXME trivial
	return 1;
}

SupportVM* SupportVM::getCopy() {
	return SupportVM(*this);
}
