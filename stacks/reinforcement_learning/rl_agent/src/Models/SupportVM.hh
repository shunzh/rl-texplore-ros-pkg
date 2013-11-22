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
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml/ml.hpp>

#include <rl_common/core.hh>

class SupportVM: public Classifier {
public:
	SupportVM(int id, int trainMode, int trainFreq, int m,
			  float featPct, Random rng);
	virtual ~SupportVM();

	virtual bool trainInstance(classPair &instance);
	virtual bool trainInstances(std::vector<classPair> &instances);
	virtual void testInstance(const std::vector<float> &input, std::map<float, float>* retval);
	virtual float getConf(const std::vector<float> &input);
	virtual SupportVM* getCopy();

private:
	const int id;

	const int mode;
	const int freq;
	const int M;
	const float featPct;
	const Random rng;

	// SVM
	CvSVMParams params;
	CvSVM SVM;
};

#endif /* SUPPORTVM_H_ */
