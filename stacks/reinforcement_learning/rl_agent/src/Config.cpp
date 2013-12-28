/*
 * Config.cpp
 *
 *  Created on: Dec 23, 2013
 *      Author: menie
 */

#include <rl_agent/Config.h>

bool Config::tranSepa = false;
bool Config::rewardGiven = false;
int Config::modelSize = 8;
int Config::modelTypesArray[] = {C45TREE, C45TREE, C45TREE, C45TREE, C45TREE, KNN, KNN, KNN};
