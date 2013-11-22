/*
 * SupportVM.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: menie
 */

#include "SupportVM.h"

SupportVM::SupportVM() {
	// TODO Auto-generated constructor stub

}

SupportVM::~SupportVM() {
	// TODO Auto-generated destructor stub
}

bool SupportVM::trainInstance(classPair& instance) {
}

bool SupportVM::trainInstances(std::vector<classPair>& instances) {
}

void SupportVM::testInstance(const std::vector<float>& input,
		std::map<float, float>* retval) {
}

float SupportVM::getConf(const std::vector<float>& input) {
}

SupportVM* SupportVM::getCopy() {
}
