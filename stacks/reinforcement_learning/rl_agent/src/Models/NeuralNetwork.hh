/*
 * MultipleLP.h
 *
 * Multiple Layer Perception (ANN), using OpenCV.
 *
 *  Created on: Nov 22, 2013
 *      Author: Shun Zhang
 */

#ifndef MULTIPLELP_H_
#define MULTIPLELP_H_

#include <rl_common/core.hh>

class NeuralNetwork: public Classifier {
public:
	NeuralNetwork(int id, int trainMode, int trainFreq, int m,
			  float featPct, Random rng);
	virtual ~NeuralNetwork();

	virtual bool trainInstance(classPair &instance);
	virtual bool trainInstances(std::vector<classPair> &instances);
	virtual void testInstance(const std::vector<float> &input, std::map<float, float>* retval);
	virtual float getConf(const std::vector<float> &input);
	virtual NeuralNetwork* getCopy();

private:
	const int id;

	const int mode;
	const int freq;
	const int M;
	const float featPct;
	const Random rng;

	pthread_mutex_t mlp_mutex;
};

#endif /* MULTIPLELP_H_ */
