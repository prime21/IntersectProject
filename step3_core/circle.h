#pragma once

#include "point.h"

#ifndef CIRCLE_H
#define CIRCLE_H

struct Circle {
	Point c;
	double r;
	Circle() {
		c = Point(0, 0);
		r = 0;
	}
	Circle(Point c, double r) :c(c), r(r) {}
	Point point(double a) const {
		return Point(c.x + cos(a) * r, c.y + sin(a) * r);
	}
};

#endif