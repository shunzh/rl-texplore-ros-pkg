/*
 * NearestNeighbors.h
 *
 *  Created on: Dec 26, 2013
 *      Author: menie
 */

#ifndef NEARESTNEIGHBORS_H_
#define NEARESTNEIGHBORS_H_

#include <rl_common/core.hh>

class NearestNeighbor: public Classifier {
public:
	NearestNeighbor();
	NearestNeighbor(NearestNeighbor* n);

  virtual bool trainInstances(std::vector<classPair> &instances);
  virtual bool trainInstance(classPair &instance);
  virtual void testInstance(const std::vector<float> &in, std::map<float, float>* retval);
  virtual float getConf(const std::vector<float> &in);
  virtual Classifier* getCopy();

  static float distance(const std::vector<float>& instanceA, const std::vector<float>& instanceB);

private:
  std::vector<classPair> data;
};

#endif /* NEARESTNEIGHBORS_H_ */
