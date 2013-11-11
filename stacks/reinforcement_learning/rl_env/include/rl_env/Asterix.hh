/*
 * Asterix.hh
 *
 * Only implement simple features of Asterix:
 * - Only agent and ghosts, ghosts would simply walk back and forth
 *
 *  Created on: Nov 10, 2013
 *      Author: menie
 */

#ifndef ASTERIX_HH_
#define ASTERIX_HH_

#include "core.hh"

class Asterix: public Environment {
public:
  Asterix(Random &rand, bool extraVariation, bool stoch);
  virtual ~Asterix();

  virtual const std::vector<float> &sensation() const;
  virtual float apply(int action);

  virtual bool terminal() const;
  virtual void reset();

  virtual int getNumActions();
  virtual void getMinMaxFeatures(std::vector<float> *minFeat, std::vector<float> *maxFeat);
  virtual void getMinMaxReward(float* minR, float* maxR);

  virtual std::vector<experience> getSeedings();

protected:
  typedef std::pair<float,float> coord_t;
  enum action_t {NORTH, EAST, SOUTH, WEST};

private:
  const int height;
  const int width;
  coord_t goal;

  const bool extraVar;
  const bool noisy;
  Random &rng;
};

#endif /* ASTERIX_HH_ */
