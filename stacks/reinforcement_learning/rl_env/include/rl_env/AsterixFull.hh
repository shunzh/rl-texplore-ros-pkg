/*
 * AsterixFull.hh
 *
 *  Created on: Dec 25, 2013
 *      Author: menie
 */

#ifndef ASTERIXFULL_HH_
#define ASTERIXFULL_HH_

#include <rl_env/Asterix.hh>

class AsterixFull: public Asterix {
public:
	AsterixFull(Random &rand, bool extraVariation, bool stoch, bool p, int f);
protected:
	void setPhase();
};

#endif /* ASTERIXFULL_HH_ */
