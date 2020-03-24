#pragma once

#include "basic.h"
#include "insect.h"
#include "point.h"
#include "line.h"
#include "circle.h"

#ifndef CALC_H
#define CALC_H
#define sqr(x) ((x)*(x))

struct solve {

//	vector< pair<double, double> > count(vector<string>);
//	int count_int(vector<string>);

//	Line getLine(string);
//	Circle getCircle(string);

	int isType(std::string now) {
		if (now[0] == 'C') return 1;
		return 0;
	}
	Line getLine(std::string a) {
		std::stringstream ss;
		char tp;
		int u, v, x, y;
		ss << a;
		ss >> tp >> u >> v >> x >> y;
		Point start(u, v);
		Point arrow(x - u, y - v);
		return Line(start, arrow, tp);
	}
	Circle getCircle(std::string a) {
		std::stringstream ss;
		char tp;
		int x, y, r;
		ss << a;
		ss >> tp >> x >> y >> r;
		return Circle(Point(x, y), r);
	}

	void getLineInter(Line a, Line b, vector<Point>& ret) {
		Point delta = b.u - a.u;
		double crs = a.v ^ b.v;
		double t1 = (delta ^ b.v) / crs;
		double t2 = (delta ^ a.v) / crs;
		if (a.online(t1) && b.online(t2)) {
			ret.push_back(a.u + a.v * t1);
		}
	}
	void getCirInter(Circle a, Circle b, vector<Point>& ret) {
		double dis2 = sqr(a.c.x - b.c.x) + sqr(a.c.y - b.c.y);
		if (dis2 > sqr(a.r + b.r)) return;
		if (dis2 < sqr(a.r - b.r)) return;

		double alpha = dis2 + sqr(a.r) - sqr(b.r);
		alpha /= 2 * sqrt(dis2);

		double h = sqrt(sqr(a.r) - sqr(alpha));

		Point o1o2 = Point(b.c) - Point(a.c);
		o1o2 = o1o2 / o1o2.length();

		Point vert = Point(o1o2.y, -o1o2.x);
		Point P = a.c + o1o2 * alpha;
		Point Q = P + vert * h;
		ret.push_back(Q);
		Q = P - vert * h;
		ret.push_back(Q);
	}
	void getLcInter(Line a, Circle b, vector<Point>& ret) {
		Point lc = a.u - b.c;
		double A = a.v.length2();
		double B = (lc * a.v) * 2;
		double C = lc.length2() - sqr(b.r);
		double delta = sqr(B) - 4 * A * C;
		if (delta >= 0) {
			delta = sqrt(delta);
			double x1 = (delta - B) / (2 * A);
			double x2 = (-delta - B) / (2 * A);

			if (a.online(x1)) ret.push_back(a.u + a.v * x1);
			if (a.online(x2)) ret.push_back(a.u + a.v * x2);
		}
	}

	vector<Point> count_line(vector<Line> s) {
		vector<Point> ret;
		for (int i = 0; i < s.size(); i++)
			for (int j = i + 1; j < s.size(); j++) {
				getLineInter(s[i], s[j], ret);
			}
		return ret;
	}
	vector<Point> count_cir(vector<Circle> s) {
		vector<Point> ret;
		for (int i = 0; i < s.size(); i++)
			for (int j = i + 1; j < s.size(); j++) {
				getCirInter(s[i], s[j], ret);
			}
		return ret;
	}
	vector<Point> count_lc(vector<Line> ls, vector<Circle> cs) {
		vector<Point> ret;
		for (int i = 0; i < ls.size(); i++)
			for (int j = 0; j < cs.size(); j++) {
				getLcInter(ls[i], cs[j], ret);
			}
		return ret;
	}

	vector< pair<double, double> > count(vector<string> s) {
		vector<Line> Ls;
		vector<Circle> Cs;

		for (auto& l : s) {
			if (isType(l) == 0) {
				Ls.push_back(getLine(l));
			}
			else {
				Cs.push_back(getCircle(l));
			}
		}

		vector< Point > tmp;
		vector< Point > ret;

		tmp = count_line(Ls);
		for (auto& p : tmp) {
			ret.push_back(p);
		}
		tmp.clear();

		tmp = count_cir(Cs);
		for (auto& p : tmp) {
			ret.push_back(p);
		}
		tmp.clear();

		tmp = count_lc(Ls, Cs);
		for (auto& p : tmp) {
			ret.push_back(p);
		}
		tmp.clear();

		sort(ret.begin(), ret.end());
		auto it = unique(ret.begin(), ret.end());
		ret.resize(distance(ret.begin(), it));

		vector< pair<double, double> > ans;
		for (auto& p : ret) ans.push_back(p.getPair());
		return ans;
	}

	int count_int(vector<string> s) {
		return count(s).size();
	}

	int isSame(string a, string b) {
		if (isType(a) == 0 && isType(b) == 0) {
			Line aa = getLine(a);
			Line bb = getLine(b);

			return aa == bb;
		}
		return 0;
	}
};
#endif // !CALC_H
