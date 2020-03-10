#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>
#include <cmath>
#include <errno.h>
#include <stddef.h>

#ifndef PMXM_INTER_H

#define PMXM_INTER_H


std::ifstream fin;
std::ofstream fout;
typedef std::pair<long long, long long> poi;

const double eps = 1e-10;

int ddcmp(double x);

struct inter {
	double x;
	double y;
	inter() { x = 0; y = 0; }
	inter(double x, double y) : x(x), y(y) {}
	inter(poi p) : x(p.first * 1.), y(p.second * 1.) {}
	bool operator == (const inter& rhs) const {
		return ddcmp(x - rhs.x) == 0 && ddcmp(y - rhs.y) == 0;
	}
	bool operator < (const inter& rhs) const {
		int d = ddcmp(x - rhs.x);
		if (d < 0) return true;
		if (d > 0) return false;
		if (ddcmp(y - rhs.y) < 0) return true;
		return false;
	}

	friend inter operator + (const inter& lhs, const inter& rhs) {
		return inter(lhs.x + rhs.x, lhs.y + rhs.y);
	}

	friend inter operator - (const inter& lhs, const inter& rhs) {
		return inter(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	friend inter operator / (const inter& lhs, const double& d) {
		return inter(lhs.x / d, lhs.y / d);
	}

	friend inter operator * (const inter& lhs, const double& d) {
		return inter(lhs.x * d, lhs.y * d);
	}

	friend double operator * (const inter& lhs, const inter& rhs) {
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	double length() {
		return sqrt(x * x + y * y);
	}

	double length2() {
		return x * x + y * y;
	}
};

#endif
