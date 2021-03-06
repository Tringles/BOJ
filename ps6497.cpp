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

int n, m, p1, p2, p3;
int p[200001];
priority_queue<PLL, vector<PLL>, greater<PLL>> q;

int find(int x) {
	if (p[x] < 0)return x;
	return find(p[x]);
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
	while (1) {
		cin >> n >> m;
		if (!n && !m)break;
		memset(p, -1, sizeof(p));
		int ans = 0;
		for (int i = 0; i < m; i++) {
			cin >> p1 >> p2 >> p3;
			q.push({ p3,{p1,p2} });
			ans += p3;
		}
		int w = 0;
		for (int i = 0; i < m; i++) {
			int d = q.top().first;
			int x = q.top().second.first, y = q.top().second.second;
			q.pop();
			if (merge(x, y))w += d;
		}
		cout << ans - w << endl;
	}
	return 0;
}
