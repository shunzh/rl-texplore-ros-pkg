/*
 * NearestNeighbors.cpp
 *
 *  Created on: Dec 26, 2013
 *      Author: menie
 */

#include "NearestNeighbor.hh"

NearestNeighbor::NearestNeighbor():
	data(0)
{
}

NearestNeighbor::NearestNeighbor(NearestNeighbor* n):
	data(n->data)
{
}

bool NearestNeighbor::trainInstances(std::vector<classPair>& instances) {
	data.insert(data.end(), instances.begin(), instances.end());

	return true;
}

bool NearestNeighbor::trainInstance(classPair& instance) {
	data.push_back(instance);

	return true;
}

void NearestNeighbor::testInstance(const std::vector<float>& in,
		std::map<float, float>* retval) {
	retval->clear();

	if (data.size() < 1) return;

	float minDist = distance(data[0].in, in);
	float minLabel = data[0].out;

	for (std::vector<classPair>::iterator it = data.begin() + 1; it != data.end(); ++it) {
		float dist = distance((*it).in, in);

		if (dist < minDist) {
			minDist = dist;
			minLabel = (*it).out;
		}
	}

	(*retval)[minLabel] = 1;
}

float NearestNeighbor::getConf(const std::vector<float>& in) {
	// TODO
	return 0;
}

Classifier* NearestNeighbor::getCopy() {
	return new NearestNeighbor(this);
}

float NearestNeighbor::distance(const std::vector<float>& instanceA,
		const std::vector<float>& instanceB) {
	float sum = 0;
	for (unsigned i = 0; i < instanceA.size(); i++) {
		sum += (instanceA[i] - instanceB[i]) * (instanceA[i] - instanceB[i]);
	}

	return sum;
}
