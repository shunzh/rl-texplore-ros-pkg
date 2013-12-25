/*
 * AsterixFull.cc
 *
 *  Created on: Dec 25, 2013
 *      Author: menie
 */

#include <rl_env/AsterixFull.hh>

AsterixFull::AsterixFull(Random &rand, bool extraVariation, bool stoch, bool p, int f):
	Asterix(rand, extraVariation, stoch, p, f)
{
}

void AsterixFull::setPhase() {
	int oneRun = (width - 1) * 2;

	// DEBUG
	if (steps % (oneRun * 2) == 0) {
		phase = GHOST;
		for (int i = 0; i < height; i++) objCate[i] = phase;
	}

	else if (steps % (oneRun * 2) == oneRun) {
		phase = FOOD;
		for (int i = 0; i < height; i++) objCate[i] = phase;
	}
}
