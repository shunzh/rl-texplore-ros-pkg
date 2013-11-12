/*
 * Asterix.hh
 *
 * Only implement simple features of Asterix:
 * - Only agent and ghosts, ghosts would simply walk back and forth
 *
 * features:
 * horizontal distance to the ghost in the current row
 * horizontal distance to the ghost in the previous row
 * horizontal distance to the ghost in the next row
 *
 *  Created on: Nov 10, 2013
 *      Author: menie
 */

#ifndef ASTERIX_HH_
#define ASTERIX_HH_

#define KILL_R -1000

#include <rl_common/core.hh>

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
  enum action_t {NORTH, EAST, SOUTH, WEST, STAY};
  enum direct_t {LEFT, RIGHT, VANISH};

  bool killed() const;
  void updateFeatures();
  void print();

private:
  const int height;
  const int width;

  const bool extraVar;
  const bool noisy;
  Random &rng;

  std::vector<int> pos;
  int &ns;
  int &ew;

  std::vector<float> s;

  // ghost[i] represent the location of ghost at line i
  int* ghost;
  // direction[i[ is the direction of movement of the ghost at row i
  direct_t* direction;
  // record number of steps
  int steps;
  int rewardGot;
};

#endif /* ASTERIX_HH_ */
