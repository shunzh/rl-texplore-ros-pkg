/*
 * OpencvClassifier.h
 *
 *  Created on: Nov 24, 2013
 *      Author: menie
 */

#ifndef OPENCVCLASSIFIER_H_
#define OPENCVCLASSIFIER_H_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml/ml.hpp>

#include <rl_common/core.hh>

class OpencvClassifier: public Classifier {
public:
	OpencvClassifier();

	/** Train the model on a vector of training instances */
	virtual bool trainInstances(std::vector<classPair> &instances) = 0;

	/** Train the model on a single training instance */
	virtual bool trainInstance(classPair &instance) = 0;

	/** Get the model's prediction for a given input */
	virtual void testInstance(const std::vector<float> &in, std::map<float, float>* retval) = 0;

	/** Get the model's confidence in its predictions for a given input. */
	virtual float getConf(const std::vector<float> &in) = 0;

	/** Get a copy of the model */
	virtual OpencvClassifier* getCopy() = 0;

	void updateMats(std::vector<classPair> &instances);

	cv::Mat getTestingMat(const std::vector<float> &input);

protected:
	cv::Mat trainingMat, labelMat;

	bool CVDEBUG;
};

#endif /* OPENCVCLASSIFIER_H_ */
