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

#include <rl_common/core.hh>
#include "OpencvClassifier.hh"

class SupportVM: public OpencvClassifier {
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

	pthread_mutex_t svm_mutex;

	// return true of labelMat contains only one type of class
	// if so, no need for training
	bool homogeneous();
};

#endif /* SUPPORTVM_H_ */
