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

int n, m, p1, p2, p3, s, f, lo, hi;
int visit[100001];
vector<vector<PI>> v;
queue<int> q;

bool bfs(int w) {
	visit[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == f)return true;
		for (auto& i : v[cur]) {
			if (!visit[i.first] && w <= i.second) {
				visit[i.first] = 1;
				q.push(i.first);
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2 >> p3;
		v[p1].push_back({ p2,p3 });
		v[p2].push_back({ p1,p3 });
		hi = max(hi, p3);
	}
	cin >> s >> f;
	while (lo < hi) {
		memset(visit, 0, sizeof(visit));
		while (!q.empty())q.pop();
		int mid = (lo + hi) >> 1;
		if (bfs(mid))lo = mid + 1;
		else hi = mid - 1;
	}
	cout << hi << endl;
	return 0;
}
