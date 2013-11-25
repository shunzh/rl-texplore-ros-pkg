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
	featPct(featPct), rng(rng), SVMDEBUG(true) {

	pthread_mutex_init(&svm_mutex, NULL);

    // Set up SVM's parameters
    params.svm_type    = CvSVM::C_SVC;
    params.kernel_type = CvSVM::LINEAR;
    params.term_crit   = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6);
}

SupportVM::~SupportVM() {
}

bool SupportVM::trainInstance(classPair& instance) {
	std::vector<classPair> vec;
	vec.push_back(instance);
	return trainInstances(vec);
}

bool SupportVM::trainInstances(std::vector<classPair>& instances) {
	pthread_mutex_lock(&svm_mutex);
	updateMats(instances);

	// we cannot train it if we have less than 2 samples
	if (! homogeneous()) {
		SVM.train(trainingMat, labelMat, Mat(), Mat(), params);
	}
	pthread_mutex_unlock(&svm_mutex);

	return true;
}

void SupportVM::testInstance(const std::vector<float>& input,
		std::map<float, float>* retval) {
	pthread_mutex_lock(&svm_mutex);
	retval->clear();

	Mat testMat = getTestingMat(input);

	// it doesn't work if it has only seen 1 or less samples
	if (homogeneous()) {
		pthread_mutex_unlock(&svm_mutex);
		return;
	}
	float predit = SVM.predict(testMat);

	if (SVMDEBUG) {
		std::cout << "Predict: " << predit << std::endl;
	}

	(*retval)[predit] = 1.0;
	pthread_mutex_unlock(&svm_mutex);
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
	if (labelMat.rows < 2) return true;

	float firstLabel = labelMat.at<float>(0, 0);
	for (int i = 1; i < labelMat.rows; i++) {
		if (labelMat.at<float>(i, 0) != firstLabel) {
			return false;
		}
	}

	return true;
}
