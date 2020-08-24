#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

struct point {
	int x, y, p, q;
	point() :point(0, 0, 1, 0) {}
	point(int x_, int y_) :point(x_, y_, 1, 0) {}
	point(int x_, int y_, int p_, int q_) :x(0), y(0), p(1), q(1) {}
	bool operator<(const point& o) {
		if (1ll * q * o.p != 1ll * p * o.q)return 1ll * q * o.p < 1ll * p * o.q;
		if (y != o.y)return y < o.y;
		return x < o.x;
	}
};

ll ccw(const point& A, const point& B, const point& C) {
	return 1ll * (B.x - A.x) * (C.y - A.y) - 1ll * (B.y - A.y) * (C.x - A.x);
}

double dist(const point& A,const point& B) {
	return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

int n, l;
double ans, d1, d2;
point p[1001];
vector<point> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> l;
	for (int i = 0; i < n; i++) 
		cin >> p[i].x >> p[i].y;
	sort(p, p + n);
	for (int i = 1; i < n; i++) {
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	sort(p + 1, p + n);
	stack<int> s;
	s.push(0);
	s.push(1);
	int next = 2;
	while (next < n) {
		while (s.size() >= 2) {
			int first = s.top();
			s.pop();
			int second = s.top();
			if (ccw(p[second], p[first], p[next]) > 0) {
				s.push(first);
				break;
			}
		}
		s.push(next++);
	}
	while (!s.empty()) {
		v.push_back(p[s.top()]);
		s.pop();
	}
	for (int i = 0; i < v.size(); i++) {
		int j = (i + 1) % v.size(), k = (i + v.size() - 1) % v.size();
		d1 = dist(v[i], v[j]);
		d2 = dist(v[i], v[k]);
		ans += d1;
		ll rad = 1ll * (v[j].x - v[i].x) * (v[k].x - v[i].x) + 1ll * (v[j].y - v[i].y) * (v[k].y - v[i].y);
		ans += l * (3.1415926 - acos(rad / d1 / d2));
	}
	cout << round(ans) << endl;
	return 0;
}
