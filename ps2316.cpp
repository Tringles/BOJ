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

int n, m, p1, p2;
int c[808][808], f[808][808], visit[808];
vector<vector<int>> v;
queue<int> q;

int max_flow(int start, int end) {
	int ans = 0;
	while (true) {
		q.push(start);
		memset(visit, -1, sizeof(visit));
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < v[cur].size(); i++) {
				int next = v[cur][i];
				if (c[cur][next] - f[cur][next] > 0 && visit[next] == -1) {
					q.push(next);
					visit[next] = cur;
					if (next == end)break;
				}
			}
		}
		if (visit[end] == -1)break;
		int flow = INF;
		for (int i = end; i != start; i = visit[i])
			flow = min(flow, c[visit[i]][i] - f[visit[i]][i]);
		for (int i = end; i != start; i = visit[i]) {
			f[visit[i]][i] += flow;
			f[i][visit[i]] -= flow;
		}
		ans += flow;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(808);
	for (int i = 1; i <= n; i++) {
		v[i].push_back(401 + i);
		v[401 + i].push_back(i);
		c[i][401 + i] = 1;
	}
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2;
		v[p1].push_back(p2 + 401);
		v[p1 + 401].push_back(p2);
		v[p2].push_back(p1 + 401);
		v[p2 + 401].push_back(p1);
		c[p1 + 401][p2] = 1;
		c[p2 + 401][p1] = 1;
	}
	cout << max_flow(402, 2) << endl;
	return 0;
}
