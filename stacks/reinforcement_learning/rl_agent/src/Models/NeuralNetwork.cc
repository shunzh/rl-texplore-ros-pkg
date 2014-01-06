/*
 * MultipleLP.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: Shun Zhang
 */

#include "NeuralNetwork.hh"

NeuralNetwork::NeuralNetwork(int id, int trainMode, int trainFreq, int m,
        float featPct, Random rng, int numLayer, int nodesPerLayer):
	id(id), mode(trainMode), freq(trainFreq), M(m),
	featPct(featPct), rng(rng) {

	// initialize network
	network.layerNum = numLayer;
	network.layerSize = new int[numLayer];

	// size of the feature is unknown now!
	network.nodes[0] = NULL;
	network.layerSize[0] = 0;

	// hidden layers
	for (int i = 1; i < numLayer - 1; i++) {
		network.nodes[i] = new Node[nodesPerLayer + 1]; // plus a bias node
		network.layerSize[i] = nodesPerLayer + 1;
	}

	// output layer
	network.nodes[numLayer - 1] = new Node[1];
  network.layerSize[numLayer - 1] = 1;

  // init weights
  w = new float**[numLayer];

  for (int i = 1; i < numLayer - 1; i++) {
  	w[i] = new float*[network.layerSize[i]];

  	// TODO
  }
	pthread_mutex_init(&ann_mutex, NULL);
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
	// first run
	if (network.nodes[0] == NULL) {
		initInputLayer(&network, instances);
	}

	// backprop TODO
}

void NeuralNetwork::testInstance(const std::vector<float>& input,
		std::map<float, float>* retval) {
	retval->clear();

	// TODO
}

float NeuralNetwork::getConf(const std::vector<float>& input) {
	// TODO
	return 1;
}

NeuralNetwork* NeuralNetwork::getCopy() {
	return new NeuralNetwork(*this);
}

void NeuralNetwork::initInputLayer(Network* net,
		std::vector<classPair>& instances) {
	if (instances.size() < 1) return;

	int featSize = instances[0].in.size();
	net->nodes[0] = new Node[featSize];
	net->layerSize[0] = 0;
}

void NeuralNetwork::resetNetwork(Network* net) {

}

std::vector<float> NeuralNetwork::forwardPass(std::vector<float> in) {
}

void NeuralNetwork::backPorp(std::vector<float> error) {
}

float NeuralNetwork::sigmoid(float x) {
	// fast sigmoid function
	return x / (1 + std::abs(x));
}
