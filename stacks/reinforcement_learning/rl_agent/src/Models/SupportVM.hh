/*
 * SupportVM.h
 *
 * Support Vector Machine, using OpenCV lib.
 *
 *  Created on: Nov 22, 2013
 *      Author: Shun Zhang
 */

#ifndef SUPPORTVM_H_
#define SUPPORTVM_H_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.h>
#include <opencv2/ml/ml.hpp>

#include "core.hh"

class SupportVM: public Classifier {
public:
	SupportVM();
	virtual ~SupportVM();

	virtual bool trainInstance(classPair &instance);
	virtual bool trainInstances(std::vector<classPair> &instances);
	virtual void testInstance(const std::vector<float> &input, std::map<float, float>* retval);
	virtual float getConf(const std::vector<float> &input);
	virtual SupportVM* getCopy();
};

#endif /* SUPPORTVM_H_ */
