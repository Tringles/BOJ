#include<bits/stdc++.h>
#include<unordered_map>
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

int p[1001], p1, p2, n, m, k;
priority_queue<PII, vector<PII>, greater<PII>> q;
vector<PI> v;
bool flag;

int find(int x) {
	if (p[x] < 0)return x;
	return p[x] = find(p[x]);
}
bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return false;
	p[x] += p[y];
	p[y] = x;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2;
		v.push_back({ p1,p2 });
	}
	for (int i = 0; i < k; i++) {
		if (m - i < n - 1)flag = true;
		if (flag) {
			cout << 0 << ' ';
			continue;
		}
		memset(p, -1, sizeof(p));
		while (!q.empty())q.pop();
		for (int j = i; j < m; j++)
			q.push({ j + 1,{v[j].first,v[j].second} });
		int w = 0, det = 0;
		for (int j = 0; j < m - i; j++) {
			int d = q.top().first;
			int x = q.top().second.first, y = q.top().second.second;
			q.pop();
			if (merge(x, y))w += d;
		}
		for (int j = 1; j <= n; j++)det = min(det, p[j]);
		if (-det != n) {
			flag = true;
			cout << 0 << ' ';
		}
		else cout << w << ' ';
	}
	cout << endl;
	return 0;
}