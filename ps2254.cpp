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

int n, ans;
point prison;
vector<point> p, tmp;
bool check[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> prison.x >> prison.y;
	for (int i = 0; i < n; i++) {
		point push;
		cin >> push.x >> push.y;
		p.push_back(push);
	}
	while (1) {
		if (p.size() < 3) {
			cout << ans << endl;
			return 0;
		}
		sort(p.begin(), p.end());
		prison.p = prison.x - p[0].x;
		prison.q = prison.y - p[0].y;
		for (int i = 1; i < p.size(); i++) {
			p[i].p = p[i].x - p[0].x;
			p[i].q = p[i].y - p[0].y;
		}
		sort(p.begin() + 1, p.end());
		stack<int> s;

		s.push(0);
		s.push(1);
		int next = 2;
		while (next < p.size()) {
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
		int start = s.top();
		while (s.size()) {
			int first = s.top(), second;
			s.pop();
			if (!s.empty())second = s.top();
			else second = start;
			if (ccw(p[second], p[first], prison) <= 0) {
				cout << ans << endl;
				return 0;
			}
			else check[first] = true;
		}
		for (int i = 0; i < p.size(); i++) {
			if (!check[i]) {
				point push;
				push.x = p[i].x, push.y = p[i].y;
				tmp.push_back(push);
			}
		}
		memset(check, 0, sizeof(check));
		p.clear();
		p = tmp;
		tmp.clear();
		ans++;
	}
	return 0;
}
