#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<double, double> PD;
typedef pair<ll, ll> PL;
typedef pair<double, pair<double, double>> PDD;
typedef pair<ll, pair<ll, ll>> PLL;
#define endl '\n'
#define INF 2e9
#define LINF 2e15
#define MOD 1000000007

double x, y, r;
int t, n, p[3003];
vector<PDD> pv;
queue<PI> q;

int find(int x) {
	if (p[x] < 0)return x;
	return p[x] = find(p[x]);
}
bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return false;
	p[y] = x;
	return true;
}
double dist(PD a, PD b) { return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2)); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		int cnt = 0;
		memset(p, -1, sizeof(p));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> r;
			pv.push_back({ x,{y,r} });
		}
		for (int i = 0; i < pv.size(); i++) {
			for (int j = 0; j < pv.size(); j++) {
				if (i == j)continue;
				if (pv[i].second.second + pv[j].second.second >= dist({ pv[i].first,pv[i].second.first }, { pv[j].first,pv[j].second.first })) {
					q.push({ i,j });
				}
			}
		}
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			merge(cur.first, cur.second);
		}
		for (int i = 0; i < n; i++)
			if (p[i] == -1)cnt++;
		cout << cnt << endl;
		pv.clear();
	}
	return 0;
}