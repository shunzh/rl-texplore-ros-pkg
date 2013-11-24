/*
 * OpencvClassifier.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: menie
 */

#include "OpencvClassifier.hh"

using namespace cv;

OpencvClassifier::OpencvClassifier() :
	CVDEBUG(false) {

}

void OpencvClassifier::updateMats(std::vector<classPair>& instances) {
	float* trainingData; // unrolled 2 dimensional array
	float* labels;
	int featureSize = instances[0].in.size();

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

	if (CVDEBUG) {
		std::cout << "Training: " << std::endl << trainingMat << std::endl;
		std::cout << "Labels: " << std::endl << labelMat << std::endl;
	}

	delete[] trainingData;
	delete[] labels;
}

Mat OpencvClassifier::getTestingMat(const std::vector<float>& input) {
	float* testData = new float[input.size()];
	std::copy(input.begin(), input.begin() + input.size(), testData);
	Mat testMat(1, input.size(), CV_32FC1, testData);

	if (CVDEBUG) {
		std::cout << "Test:" << std::endl << testMat << std::endl;
	}

	delete[] testData;

	return testMat;
}
