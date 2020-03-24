
#include "pch.h"
#include "insect.h"
#include "basic.h"

#pragma once

#ifndef POINT_H

#define POINT_H

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	void read() {
		cin >> x >> y;
	}
	void print() {
		printf("%.10lf %.10lf\n", x, y);
	}
	
	bool operator == (const Point& rhs) const {
		return (dcmp(x - rhs.x) == 0) && (dcmp(y - rhs.y) == 0);
	}

	bool operator < (const Point& rhs) const {
		int d = dcmp(x - rhs.x);
		if (d < 0) return true;
		if (d > 0) return false;
		if (dcmp(y - rhs.y)) return true;
		return false;
	}

	friend Point operator + (const Point& lhs, const Point& rhs) {
		return Point(lhs.x + rhs.x, lhs.y + rhs.y);
	}

	friend Point operator - (const Point& lhs, const Point& rhs) {
		return Point(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	friend Point operator / (const Point& lhs, const double& d) {
		return Point(lhs.x / d, lhs.y / d);
	}

	friend Point operator * (const Point& lhs, const double& d) {
		return Point(lhs.x * d, lhs.y * d);
	}

	friend double operator * (const Point& lhs, const Point& rhs) {
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	friend double operator ^(const Point& lhs, const Point& rhs) {
		return lhs.x * rhs.y - lhs.y * rhs.x;
	}

	double length() {
		return sqrt(x * x + y * y);
	}

	double length2() {
		return x * x + y * y;
	}
	
	pair<double, double> getPair() {
		return make_pair(x, y);
	}


};
typedef Point Vector;

#endif // !POINT_H