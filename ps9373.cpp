#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
typedef pair<int, pair<int, int>> PII;
typedef pair<ll, pair<ll, ll>> PLL;
#define endl '\n'
#define INF 2e9
#define LINF 2e15
#define MOD 1000000007

int t, n, p[1005];
double w;

typedef pair<double, pair<double, double>> PDD;

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
double dist(PDD a, PDD b) {
	double dis = sqrt((a.first - b.first) * (a.first - b.first) + (a.second.first - b.second.first) * (a.second.first - b.second.first));
	return max((double)0, dis - a.second.second - b.second.second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		memset(p, -1, sizeof(p));
		cin >> w >> n;
		if (!n)	cout << fixed << setprecision(6) << w / 2 << endl;
		else {
			vector<PDD> v;
			for (int i = 0; i < n; i++) {
				double p1, p2, p3;
				cin >> p1 >> p2 >> p3;
				v.push_back({ p1,{p2,p3} });
			}
			priority_queue<PDD, vector<PDD>, greater<PDD>> q;
			int l = n, r = n + 1;
			for (int i = 0; i < n; i++) {
				q.push({ max(0.0, v[i].first - v[i].second.second) ,{i,l} });
				q.push({ max(0.0, w - v[i].first - v[i].second.second),{i,r} });
				for (int j = i + 1; j < n; j++) {
					q.push({ dist(v[i],v[j]),{i,j} });
				}
			}
			while (!q.empty()) {
				double cdist = q.top().first;
				int x = q.top().second.first, y = q.top().second.second;
				q.pop();
				if (merge(x, y)) {
					if (find(l) == find(r)) {
						cout << fixed << setprecision(6) << cdist / 2 << endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}
