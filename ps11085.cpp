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

int n, m, s, e, p[1005];
vector<PII> v;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> s >> e;
	memset(p, -1, sizeof(p));
	for (int i = 0, p1, p2, p3;i < m;i++) {
		cin >> p1 >> p2 >> p3;
		v.push_back({ p3,{p1,p2} });
	}
	sort(v.rbegin(), v.rend());
	for (auto& i : v) {
		int w = i.first;
		int x = i.second.first;
		int y = i.second.second;
		merge(x, y);
		if (find(s) == find(e)) {
			cout << w << endl;
			return 0;
		}
	}
	return 0;
}