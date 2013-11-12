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
	steps = 0;
	ghost = new int[height];
	direction = new direct_t[height];

	reset();
}

Asterix::~Asterix() {
	delete[] ghost;
	delete[] direction;
}

const std::vector<float> &Asterix::sensation() const {
	return s;
}

float Asterix::apply(int action) {
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
	if (killed()) return KILL_R;

	// advance of ghosts
	for (int i = 0; i < height; i++) {
		if (direction[i] == LEFT) {
			if (ghost[i] == 0) {
				// make a turn
				ghost[i] = 1;
				direction[i] = RIGHT;
			}
			else {
				ghost[i]--;
			}
		}
		else {
			if (ghost[i] == width - 1) {
				// make a turn
				ghost[i] = width - 2;
				direction[i] = LEFT;
			}
			else {
				ghost[i]++;
			}
		}
	}

	// survival check, again
	if (killed()) return KILL_R;

	// maintaining stuff
	updateFeatures();
	steps++;

	print();

	// reward for being alive
	return 1;
}

void Asterix::updateFeatures() {
	s[0] = ghost[ns] - ew;

	if (ns > 0) s[1] = ghost[ns - 1] - ew;
	else s[1] = ghost[ns] - ew; // if no previous row, use the position in this row

	if (ns < height) s[2] = ghost[ns + 1] - ew;
	else s[2] = ghost[ns] - ew; // if no following row, use the position in this row
}

bool Asterix::killed() const {
	return ghost[ns] == ew;
}

bool Asterix::terminal() const {
	return killed() || steps > 200;
}

void Asterix::reset() {
	// set agent
	ns = 0;
	ew = width / 2;

	// set ghosts
	ghost[0] = -1; // no ghost in the first row
	for (int i = 0; i < height; i++) {
		if (i % 2 == 0) {
			// place the ghost at the left-most side
			direction[i] = RIGHT;
			ghost[i] = 0;
		}
		else {
			direction[i] = LEFT;
			ghost[i] = width - 1;
		}
	}

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
	*minR = KILL_R;
	*maxR = 1;
}

void Asterix::print() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (ghost[i] == j)
				std::cout << "G";
			else if (ns == i && ew == j)
				std::cout << "A";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

std::vector<experience> Asterix::getSeedings() {
	// return seedingsW
	std::vector<experience> seeds;

	reset();
	return seeds;
}
