/*
 * MultipleLP.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: Shun Zhang
 */

#include "NeuralNetwork.hh"

NeuralNetwork::NeuralNetwork(int id, int trainMode, int trainFreq, int m,
        float featPct, Random rng):
	id(id), mode(trainMode), freq(trainFreq), M(m),
	featPct(featPct), rng(rng) {

	pthread_mutex_init(&mlp_mutex, NULL);
}

NeuralNetwork::~NeuralNetwork() {
	// TODO Auto-generated destructor stub
}

bool NeuralNetwork::trainInstance(classPair& instance) {
	std::vector<classPair> vec;
	vec.push_back(instance);
	return trainInstances(vec);
}

bool NeuralNetwork::trainInstances(std::vector<classPair>& instances) {

}

void NeuralNetwork::testInstance(const std::vector<float>& input,
		std::map<float, float>* retval) {
	retval->clear();
}

float NeuralNetwork::getConf(const std::vector<float>& input) {
	// FIXME dummy
	return 1;
}

NeuralNetwork* NeuralNetwork::getCopy() {
	return new NeuralNetwork(*this);
}
