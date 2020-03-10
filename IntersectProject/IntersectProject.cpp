#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>
#include <cmath>

typedef std::pair<long long, long long> poi;

const double eps = 1e-10;

enum objtp {
	LINE, CIRCLE, NOTP
};

int dcmp(double x) {
	if (fabs(x) < eps) return 0;
	if (x > eps) return 1;
	return -1;
}

long long mygcd(long long n1, long long n2) {
	return (n2 == 0) ? n1 : mygcd(n2, n1 % n2);
}

struct inter {
	double x;
	double y;
	inter() { x = 0; y = 0; }
	inter(double x, double y) : x(x), y(y) {}
	inter(poi p) : x(p.first * 1.), y(p.second * 1.) {}
	bool operator == (const inter& rhs) const {
		return dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) == 0;
	}
	bool operator < (const inter& rhs) const {
		int d = dcmp(x - rhs.x);
		if (d < 0) return true;
		if (d > 0) return false;
		if (dcmp(y - rhs.y) < 0) return true;
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

std::vector<inter> gb_in;

struct obj{
	objtp type;
	obj() {}
	obj(objtp t) :type(t){}
} *pro[505050];
struct line : public obj {
	poi a;
	poi b;
	long long A, B, C;
	line() {}
	line(poi a, poi b) : obj(LINE),a(a), b(b) {

		A = a.second - b.second;
		B = b.first - a.first;
		C = a.second * (a.first - b.first) - a.first * (a.second - b.second);
		long long D = mygcd(mygcd(A, B), C);
		A /= D;
		B /= D;
		C /= D;
	}
};

struct circle : public obj {
	poi o;
	long long r;
	circle(poi o, int r): obj(CIRCLE),o(o), r(r) {}
};

int n;
bool IsSimple;

void Init() {
	char op[10];
	int u, v, x ,y, r;

	IsSimple = 1;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> op;
		if (op[0] == 'L') {
			std::cin >> x >> y >> u >> v;
			pro[i] = new line(poi(x, y), poi(u, v));
		}
		else {
			std::cin >> x >> y >> r;
			pro[i] = new circle(poi(x, y), r);
			IsSimple = 0;
		}
	}
}

void addLineInter(int i, int j) {
	line *lhs = (line *)(pro[i]);
	line *rhs = (line *)(pro[j]);
	
	long long D = (lhs->A * rhs->B) - (rhs->A * lhs->B);

	if (D == 0) return ;
	double xx = (lhs->B * 1. * rhs->C) - (rhs->B * lhs->C);
	double yy = (lhs->A * 1. * rhs->C) - (rhs->A * lhs->C);

	gb_in.push_back(inter(xx / D, yy / D));
}

void addCircleInter(int i, int j) {
	circle* lhs = (circle*)(pro[i]);
	circle* rhs = (circle*)(pro[j]);

	long long dis = (lhs->o.first - rhs->o.first) * (lhs->o.first - rhs->o.first) + (lhs->o.second - rhs->o.second) * (lhs->o.second - rhs->o.second);

	if (dis > (lhs->r + rhs->r) * (lhs->r + rhs->r)) return; 
	if (dis < (lhs->r - rhs->r) * (lhs->r - rhs->r)) return;
	
	double alpha = dis + lhs->r * lhs->r - rhs->r * rhs->r;
	alpha /= 2 * sqrt(dis);

	double h = std::sqrt(lhs->r * lhs->r - alpha * alpha);

	inter o1o2 = inter(rhs->o) - inter(lhs->o);
	o1o2 = o1o2 / o1o2.length();
	inter vert = inter(o1o2.y, -o1o2.x);
	inter P = inter(lhs->o) + o1o2 * alpha;
	inter Q = P + vert * h;
	gb_in.push_back(Q);
	Q = P - vert * h;
	gb_in.push_back(Q);
}

void addLcInter(int i, int j) {
	line* lhs = (line*)(pro[i]);
	circle* rhs = (circle*)(pro[j]);

	inter li = inter(lhs->b) - inter(lhs->a);
	inter lc = inter(lhs->a) - inter(rhs->o);

	double A = li.length2();
	double B = (lc * li) * 2;
	double C = lc.length2() - (rhs->r) * (rhs->r);

	double delta = B * B - 4 * A * C;
	if (delta >= 0) {

		delta = sqrt(delta);

		double x1 = (delta - B) / (2 * A);
		double x2 = (-delta - B) / (2 * A);

		inter t1 = inter(lhs->a) + li * x1;
		inter t2 = inter(lhs->a) + li * x2;
		gb_in.push_back(t1);
		gb_in.push_back(t2);
	}
}

void BF(){
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (pro[i] -> type == LINE && pro[j] -> type == LINE) addLineInter(i, j);
			else if (pro[i] ->type == CIRCLE && pro[j] -> type == CIRCLE) addCircleInter(i, j);
			else {
				if (pro[i] -> type == LINE) addLcInter(i, j);
				else addLcInter(j, i);
			}
		}
	}

	std::sort(gb_in.begin(),gb_in.end());
	auto it = std::unique(gb_in.begin(), gb_in.end());
	gb_in.resize(std::distance(gb_in.begin(), it));
	std::cout << gb_in.size() << std::endl;

}

void Linear_count() {
	// WA
}

int main()
{
	Init();
	//if (n <= 1000 || IsSimple == 0) {
		BF();
	//}
	//else {
	//	Linear_count();
	//}
	return 0;
}
