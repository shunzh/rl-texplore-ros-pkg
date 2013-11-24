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

	Mat layers = Mat(4, 1, CV_32SC1) ;
	// FIXME first layer depends on data
	layers.row(0) = Scalar (8);
	layers.row(1) = Scalar (10);
	layers.row(2) = Scalar (15);
	layers.row(3) = Scalar (1);

	mlp.create(layers);
}

MultipleLP::~MultipleLP() {
	// TODO Auto-generated destructor stub
}

bool MultipleLP::trainInstance(classPair& instance) {
	std::cerr << "MultipleLP: trainInstance called." << std::endl;
	return false;
}

bool MultipleLP::trainInstances(std::vector<classPair>& instances) {
	pthread_mutex_lock(&mlp_mutex);
	updateMats(instances);

	mlp.train(trainingMat, labelMat, Mat());
	pthread_mutex_unlock(&mlp_mutex);

	return true;
}

void MultipleLP::testInstance(const std::vector<float>& input,
		std::map<float, float>* retval) {
	retval->clear();

	pthread_mutex_lock(&mlp_mutex);
	Mat testMat = getTestingMat(input);
	float* output = new float();
	Mat responseMat(1, 1, CV_32FC1, output);

	mlp.predict(testMat, responseMat);
	pthread_mutex_unlock(&mlp_mutex);

	float result = responseMat.at<float>(0 ,0);

	(*retval)[result] = 1;
}

float MultipleLP::getConf(const std::vector<float>& input) {
	// FIXME trivial
	return 1;
}

MultipleLP* MultipleLP::getCopy() {
	return new MultipleLP(*this);
}
