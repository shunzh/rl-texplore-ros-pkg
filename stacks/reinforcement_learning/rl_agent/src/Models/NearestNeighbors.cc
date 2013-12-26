/*
 * NearestNeighbors.cpp
 *
 *  Created on: Dec 26, 2013
 *      Author: menie
 */

#include "NearestNeighbors.hh"

NearestNeighbors::NearestNeighbors():
	data(0)
{
}

bool NearestNeighbors::trainInstances(std::vector<classPair>& instances) {
	data.insert(data.end(), instances.begin(), instances.end());

	return true;
}

bool NearestNeighbors::trainInstance(classPair& instance) {
	data.push_back(instance);

	return true;
}

void NearestNeighbors::testInstance(const std::vector<float>& in,
		std::map<float, float>* retval) {
}

float NearestNeighbors::getConf(const std::vector<float>& in) {
}

Classifier* NearestNeighbors::getCopy() {
}

float NearestNeighbors::distance(std::vector<float> instanceA,
		std::vector<float> instanceB) {
}
