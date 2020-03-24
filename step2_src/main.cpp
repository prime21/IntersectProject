#include "calc.h"

int main(int argc, char* argv[]) {
	for (int i = 0; i < argc; ++i) {
		if (argv[i][0] == '-' && argv[i][1] == 'o') 
			freopen(argv[i + 1], "w", stdout);
		if (argv[i][0] == '-' && argv[i][1] == 'i') 
			freopen(argv[i + 1], "r", stdin);
	}

	int n;
	string now;
	vector<string> v;

	getline(cin,now);

	n = stoi(now);

	for (int i = 1; i <= n; i++) {
		getline(cin,now);
		v.push_back(now);
	}
	solve mysolve;
	vector< pair<double,double> > ans = mysolve.count(v);

	vector<Point> test;

	Line l = mysolve.getLine(v[1]);
	Circle c = mysolve.getCircle(v[0]);
	mysolve.getLcInter(l,c,test);
	for (auto &p: test) {
		cerr << p.x << " " << p.y << endl;
	}

	for (auto &p : ans) {
		cerr << p.first << " " << p.second << endl;
	}
	return 0;
}
