/*
 * NeuralNetwork.hh
 *
 * refer on http://fann.sourceforge.net/report/node4.html
 *
 *  Created on: Nov 22, 2013
 *      Author: Shun Zhang
 */

#ifndef MULTIPLELP_H_
#define MULTIPLELP_H_

#include <rl_common/core.hh>

struct Node {
	float in, out;
};

struct Network {
	Node** nodes;
	int* layerSize;
	int layerNum;
};

class NeuralNetwork: public Classifier {
public:
	NeuralNetwork(int id, int trainMode, int trainFreq, int m,
			  float featPct, Random rng, int numLayer, int nodesLayer);
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

	Network network;

	pthread_mutex_t ann_mutex;

	void initInputLayer(Network* net, std::vector<classPair>& instances);
};

#endif /* MULTIPLELP_H_ */
