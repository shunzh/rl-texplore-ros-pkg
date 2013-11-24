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
	featPct(featPct), rng(rng), SVMDEBUG(false) {

	pthread_mutex_init(&svm_mutex, NULL);
}

SupportVM::~SupportVM() {
}

bool SupportVM::trainInstance(classPair& instance) {
	std::cerr << "SupportVM: trainInstance called." << std::endl;
	return false;
}

bool SupportVM::trainInstances(std::vector<classPair>& instances) {
	updateMats(instances);

	// we cannot train it if we have less than 2 samples
	pthread_mutex_lock(&svm_mutex);
	if (! homogeneous()) {
		SVM.train(trainingMat, labelMat);
	}
	pthread_mutex_unlock(&svm_mutex);

	return true;
}

void SupportVM::testInstance(const std::vector<float>& input,
		std::map<float, float>* retval) {
	Mat testMat = getTestingMat(input);

	pthread_mutex_lock(&svm_mutex);
	// it doesn't work if it has only seen 1 or less samples
	if (homogeneous()) {
		pthread_mutex_unlock(&svm_mutex);
		return;
	}
	float predit = SVM.predict(testMat);
	pthread_mutex_unlock(&svm_mutex);

	if (SVMDEBUG) {
		std::cout << "Predict: " << predit << std::endl;
	}

	(*retval)[predit] = 1.0;

	return;
}

float SupportVM::getConf(const std::vector<float>& input) {
	// FIXME trivial
	return 1;
}

SupportVM* SupportVM::getCopy() {
	SupportVM* svm = new SupportVM(*this);
	return svm;
}

bool SupportVM::homogeneous() {
	if (labelMat.rows < 10) return true;

	float firstLabel = labelMat.at<float>(0, 0);
	for (int i = 1; i < labelMat.rows; i++) {
		if (labelMat.at<float>(i, 0) != firstLabel) {
			return false;
		}
	}

	return true;
}
