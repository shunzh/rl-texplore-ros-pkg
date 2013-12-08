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
 * ghost / food phase
 *
 *  Created on: Nov 10, 2013
 *      Author: menie
 */

#ifndef ASTERIX_HH_
#define ASTERIX_HH_

#include <rl_common/core.hh>
#include <iterator>

class Asterix: public Environment {
public:
  Asterix(Random &rand, bool extraVariation, bool stoch, bool p, int f);
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
  enum direct_t {LEFT, RIGHT};
  enum object_t {GHOST, FOOD, NOTHING};

  bool killed() const;
  bool bonus();
  void updateFeatures();
  void resetPhase();
  void setPhase();
  void print();

private:
  const int height;
  const int width;

  const bool extraVar;
  const bool noisy;
  const bool prints;
  Random &rng;

  std::vector<int> pos;
  int &ns;
  int &ew;

  std::vector<float> s;

  // object[i] represent the location of object at line i
  int* objPos;
  // direction[i[ is the direction of movement of the ghost at row i
  direct_t* direction;
  // object category for row i
  object_t* objCate;
  // record number of steps
  int steps;
  // current phase
  object_t phase;

  /**
   *  0 - this row and surronding rows
   *  1 - everything
   *  2 - ONLY the object in this row
   */
  int featureSet;
};

#endif /* ASTERIX_HH_ */
