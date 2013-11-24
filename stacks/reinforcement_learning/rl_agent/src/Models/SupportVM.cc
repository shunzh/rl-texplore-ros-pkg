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
	float* trainingData; // unrolled 2 dimensional array
	float* labels;
	int featureSize = instances[0].in.size();

	// FIXME weird problem
	if (featureSize < 0 || featureSize > 100) return false;

	trainingData = new float[instances.size() * featureSize];

	labels = new float[instances.size()];

	for(std::vector<classPair>::iterator it = instances.begin(); it != instances.end(); ++it) {
		int index = it - instances.begin();

		std::copy((*it).in.begin(), (*it).in.begin() + featureSize, trainingData + index * featureSize);

		labels[index] = (*it).out;
	}

	Mat trainingInc(instances.size(), featureSize, CV_32FC1, trainingData);
	Mat labelInc(instances.size(), 1, CV_32FC1, labels);

	trainingMat.push_back(trainingInc);
	labelMat.push_back(labelInc);

	if (SVMDEBUG) {
		std::cout << "Train instances for " << this->id << std::endl;
		std::cout << trainingMat << std::endl << labelMat << std::endl;
	}

	// we cannot train it if we have less than 2 samples
	pthread_mutex_lock(&svm_mutex);
	if (! homogeneous()) {
		SVM.train(trainingMat, labelMat);
	}
	pthread_mutex_unlock(&svm_mutex);

	delete[] trainingData;
	delete[] labels;

	return true;
}

void SupportVM::testInstance(const std::vector<float>& input,
		std::map<float, float>* retval) {
	float* testData = new float[input.size()];
	std::copy(input.begin(), input.begin() + input.size(), testData);

	Mat testMat(1, input.size(), CV_32FC1, testData);

	pthread_mutex_lock(&svm_mutex);
	// it doesn't work if it has only seen 1 or less samples
	if (homogeneous()) {
		pthread_mutex_unlock(&svm_mutex);
		return;
	}

	// DEBUG
	float predit = 0; // SVM.predict(testMat);
	pthread_mutex_unlock(&svm_mutex);

	if (SVMDEBUG) {
		std::cout << "Predict: " << predit << std::endl;
	}

	(*retval)[predit] = 1.0;

	delete[] testData;

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
