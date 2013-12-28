/*
 * Config.h
 *
 *  Created on: Dec 23, 2013
 *      Author: menie
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <rl_common/core.hh>

class Config {
public:
	static bool tranSepa;
	static bool rewardGiven;
	static int modelSize;
	static int modelTypesArray[];
};

#endif /* CONFIG_H_ */
