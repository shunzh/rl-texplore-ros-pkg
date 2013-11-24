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

	// FIXME first layer depends on data
	Mat layers = Mat(4, 1, CV_32SC1) ;
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

	mlp.train(trainingMat, labelMat, Mat());

	delete[] trainingData;
	delete[] labels;

	return true;
}

void MultipleLP::testInstance(const std::vector<float>& input,
		std::map<float, float>* retval) {
	float* testData = new float[input.size()];
	float* output = new float();
	std::copy(input.begin(), input.begin() + input.size(), testData);

	Mat testMat(1, input.size(), CV_32FC1, testData);
	Mat responseMat(1, 1, CV_32FC1, output);

	mlp.predict(testMat, responseMat);
	float result = responseMat.at<float>(0 ,0);

	(*retval)[result] = 1;

	delete[] testData;
}

float MultipleLP::getConf(const std::vector<float>& input) {
	// FIXME trivial
	return 1;
}

MultipleLP* MultipleLP::getCopy() {
	return new MultipleLP(*this);
}
