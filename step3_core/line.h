#pragma once

#include "point.h"


#ifndef LINE_H
#define LINE_H

struct Line {
	int id;
	char tp;
	Point u;
	Point v;
	Line() { id = 0;  tp = 'L'; }
	Line(Point u, Point v) :u(u), v(v) { id = 0; tp = 'L'; }
	Line(Point u, Point v, char tp) :u(u), v(v), tp(tp) { id = 0; }
	bool operator == (const Line& A) const {
		if (tp != A.tp) {
			return 0;
		}
		if (tp == 'S') {
			if (u == A.u)
				return v == A.v;
			Point uv = u + v;
			Point auv = A.u + A.v;
			if (uv == A.u)
				return u == auv;
			return false;
		}
		if (tp == 'R') {
			return u == A.u && !dcmp(v.y * A.v.x - A.v.y * v.x);
		}
		return !dcmp(v.y * A.v.x - A.v.y * v.x) && !dcmp((u - A.u) ^ (u - (A.u + A.v)));
	}
	Point point(double t) const {
		return u + v * t;
	}
	bool online(Point x) {
	
	}
	bool online(double len) {
		if (tp == 'R') {
			return dcmp(len) >= 0;
		}
		else if (tp == 'S') {
			return dcmp(len) >= 0 && dcmp(1 - len) >=0;
		}
		return 1;
	}
};

struct Segment {
	Point A, B;
};

#endif
