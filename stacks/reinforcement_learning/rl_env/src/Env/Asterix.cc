/*
 * Asterix.cc
 *
 *  Created on: Nov 10, 2013
 *      Author: menie
 */

#include <rl_env/Asterix.hh>

Asterix::Asterix(Random &rand, bool extraVariation, bool stoch, bool p):
	height(6), width(15),
	pos(2),
	s(4),
	ns(pos[0]),
	ew(pos[1]),
	extraVar(extraVariation),
	noisy(stoch),
	rng(rand),
	prints(p)
{
	objPos = new int[height];
	direction = new direct_t[height];
	objCate = new object_t[height];

	reset();
}

Asterix::~Asterix() {
	delete[] objPos;
	delete[] direction;
}

const std::vector<float> &Asterix::sensation() const {
	return s;
}

float Asterix::apply(int action) {
	float reward = 0;

	if (steps % ((width + 1) * 2) == 0 && steps != 0) {
		setPhase();
	}

	// advance of agent
	if (action == NORTH && ns > 0) {
		ns--;
	}
	else if (action == SOUTH && ns < height - 1) {
		ns++;
	}
	else if (action == WEST && ew > 0) {
		ew--;
	}
	else if (action == EAST && ew < width - 1) {
		ew++;
	}

	// survival check
	if (killed()) return -1000;
	if (bonus()) reward = 200;

	// advance of objects
	for (int i = 0; i < height; i++) {
		if (direction[i] == LEFT) {
			if (objPos[i] == -1) {
				// make a turn
				direction[i] = RIGHT;
			}
			else {
				objPos[i]--;
			}
		}
		else {
			if (objPos[i] == width) {
				// make a turn
				direction[i] = LEFT;
			}
			else {
				objPos[i]++;
			}
		}
	}

	// survival check, again
	if (killed()) return -1000;
	if (bonus()) reward = 200;

	// maintaining stuff
	updateFeatures();
	steps++;

	// debug
	if (prints) print();

	// reward for being alive
	return reward + 1;
}

void Asterix::setPhase() {
	object_t obj;
	if (objCate[0] == GHOST) {
		obj = FOOD;
	}
	else obj = GHOST;

	for (int i = 0; i < height; i++) objCate[i] = obj;
}

void Asterix::resetPhase() {
	for (int i = 0; i < height; i++) objCate[i] = GHOST;
}

void Asterix::updateFeatures() {
	s[0] = objPos[ns] - ew;

	if (ns > -1) s[1] = objPos[ns - 1] - ew;
	else s[1] = objPos[ns] - ew; // if no previous row, use the position in this row

	if (ns < height) s[2] = objPos[ns + 1] - ew;
	else s[2] = objPos[ns] - ew; // if no following row, use the position in this row

	if (objCate[0] == GHOST) s[3] = 1;
	else s[3] = 0;
}

bool Asterix::killed() const {
	return objPos[ns] == ew && objCate[ns] == GHOST;
}

bool Asterix::bonus() {
	if (objPos[ns] == ew && objCate[ns] == FOOD) {
		objCate[ns] = NOTHING;
		foodPicked++;
		return true;
	}
	else return false;
}

bool Asterix::terminal() const {
	return killed() || steps > 200;
}

void Asterix::reset() {
	// set agent
	ns = 0;
	ew = width / 2;

	// set ghosts
	for (int i = 0; i < height; i++) {
		if (i % 2 == 0) {
			// place the ghost at the left-most side
			direction[i] = RIGHT;
			objPos[i] = -1;
		}
		else {
			direction[i] = LEFT;
			objPos[i] = width;
		}
	}

	resetPhase();

	steps = 0;
}

int Asterix::getNumActions() {
	return 5;
}

void Asterix::getMinMaxFeatures(std::vector<float> *minFeat, std::vector<float> *maxFeat) {
	minFeat->resize(s.size(), -width);
	maxFeat->resize(s.size(), width);
}

void Asterix::getMinMaxReward(float* minR, float* maxR) {
	*minR = -1000;
	*maxR = 20;
}

void Asterix::print() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (objPos[i] == j && objCate[i] == GHOST)
				std::cout << "X";
			else if (objPos[i] == j && objCate[i] == FOOD)
				std::cout << "O";
			else if (ns == i && ew == j)
				std::cout << "A";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "==========================" << std::endl;
}

std::vector<experience> Asterix::getSeedings() {
	// return seedingsW
	std::vector<experience> seeds;

	reset();
	return seeds;
}
