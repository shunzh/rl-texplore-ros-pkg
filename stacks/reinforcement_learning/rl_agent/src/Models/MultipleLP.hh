/*
 * MultipleLP.h
 *
 * Multiple Layer Perception (ANN), using OpenCV.
 *
 *  Created on: Nov 22, 2013
 *      Author: Shu Zhang
 */

#ifndef MULTIPLELP_H_
#define MULTIPLELP_H_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.h>
#include <opencv2/ml/ml.hpp>

#include "core.hh"

class MultipleLP: public Classifier {
public:
	MultipleLP();
	virtual ~MultipleLP();

	virtual bool trainInstance(classPair &instance);
	virtual bool trainInstances(std::vector<classPair> &instances);
	virtual void testInstance(const std::vector<float> &input, std::map<float, float>* retval);
	virtual float getConf(const std::vector<float> &input);
	virtual MultipleLP* getCopy();
};

#endif /* MULTIPLELP_H_ */
