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
	int featureSize = instances[0].in.size();

	trainingData = new float*[instances.size()];

	labels = new float[instances.size()];

	for(std::vector<classPair>::iterator it = instances.begin(); it != instances.end(); ++it) {
		int index = it - instances.begin();

		trainingData[index] = new float[featureSize];

		std::copy((*it).in.begin(), (*it).in.begin() + featureSize, trainingData[index]);

		labels[index] = (*it).out;
	}

	Mat trainingMat(instances.size(), featureSize, CV_32FC1, trainingData);
	Mat labelMat(instances.size(), 1, CV_32FC1, labels);

	SVM.train(trainingMat, labelMat);

	return true;
}

void SupportVM::testInstance(const std::vector<float>& input,
		std::map<float, float>* retval) {
	float* testData = new float[input.size()];
	std::copy(input.begin(), input.begin() + input.size(), testData);

	Mat testMat(input.size(), 1, CV_32FC1, testData);

	float predit = SVM.predict(testMat, false);

	(*retval)[predit] = 1.0;
}

float SupportVM::getConf(const std::vector<float>& input) {
	// FIXME trivial
	return 1;
}

SupportVM* SupportVM::getCopy() {
	SupportVM* svm = new SupportVM(*this);
	return svm;
}
