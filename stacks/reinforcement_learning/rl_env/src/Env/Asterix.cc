/*
 * Asterix.cc
 *
 *  Created on: Nov 10, 2013
 *      Author: menie
 */

#include <rl_env/Asterix.hh>

Asterix::Asterix(Random &rand, bool extraVariation, bool stoch):
	height(6), width(15),
	pos(2),
	s(3),
	ns(pos[0]),
	ew(pos[1]),
	extraVar(extraVariation),
	noisy(stoch),
	rng(rand)
{
	object = new int[height];
	direction = new direct_t[height];
	objCate = new object_t[height];

	reset();
}

Asterix::~Asterix() {
	delete[] object;
	delete[] direction;
}

const std::vector<float> &Asterix::sensation() const {
	return s;
}

float Asterix::apply(int action) {
	// TODO at some frequency, reset food / ghost
	setPhase();

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
	if (killed()) return 0;
	if (bonus()) return 200;

	// advance of ghosts
	for (int i = 0; i < height; i++) {
		if (direction[i] == LEFT) {
			if (object[i] == 0) {
				// make a turn
				object[i] = 1;
				direction[i] = RIGHT;
			}
			else {
				object[i]--;
			}
		}
		else {
			if (object[i] == width - 1) {
				// make a turn
				object[i] = width - 2;
				direction[i] = LEFT;
			}
			else {
				object[i]++;
			}
		}
	}

	// survival check, again
	if (killed()) return 0;
	if (bonus()) return 200;

	// maintaining stuff
	updateFeatures();
	steps++;

	// debug
	print();

	// reward for being alive
	return 1;
}

void Asterix::setPhase() {
	if (object[0] == 0)
		for (int i = 0; i < height; i++) objCate[i] = GHOST;
}

void Asterix::resetPhase() {
	for (int i = 0; i < height; i++) objCate[i] = GHOST;
}

void Asterix::updateFeatures() {
	s[0] = object[ns] - ew;

	if (ns > 0) s[1] = object[ns - 1] - ew;
	else s[1] = object[ns] - ew; // if no previous row, use the position in this row

	if (ns < height) s[2] = object[ns + 1] - ew;
	else s[2] = object[ns] - ew; // if no following row, use the position in this row
}

bool Asterix::killed() const {
	return object[ns] == ew && objCate[ns] == GHOST;
}

bool Asterix::bonus() const {
	if (object[ns] == ew && objCate[ns] == FOOD) {
		object[ns] = NOTHING;
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
			object[i] = 0;
		}
		else {
			direction[i] = LEFT;
			object[i] = width - 1;
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
	*minR = 0;
	*maxR = 1;
}

void Asterix::print() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (object[i] == j && objCate[i] == GHOST)
				std::cout << "X";
			else if (object[i] == j && objCate[i] == FOOD)
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
