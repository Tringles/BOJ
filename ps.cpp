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

const int N = 100;
const int V = 2 * (N + 1);
const int S = V - 2;
const int E = V - 1;

int n, m, p1, p2;
int c[401][401], f[401][401], Visit[401], d[401][401], dist[401];
bool inq[401];
vector<vector<int>> v;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(N * 2 + 4);
	for (int i = N; i < N + n; i++) {
		cin >> c[i][E];
		v[E].push_back(i);
		v[i].push_back(E);
	}
	for (int i = 0; i < m; i++) {
		cin >> c[S][i];
		v[S].push_back(i);
		v[i].push_back(S);
	}
	for (int i = 0; i < m; i++) {
		for (int j = N; j < N + n; j++) {
			cin >> d[i][j];
			c[i][j] = INF;
			d[j][i] = -d[i][j];
			v[i].push_back(j);
			v[j].push_back(i);
		}
	}
	int ans = 0;
	while (true) {
		memset(Visit, -1, sizeof(Visit));
		fill(dist, dist + V, INF);
		dist[S] = 0;
		inq[S] = true;
		q.push(S);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			inq[cur] = false;
			for (auto& i : v[cur]) {
				if (c[cur][i] - f[cur][i] > 0 && dist[i] > dist[cur] + d[cur][i]) {
					dist[i] = dist[cur] + d[cur][i];
					Visit[i] = cur;
					if (!inq[i]) {
						q.push(i);
						inq[i] = true;
					}
				}
			}
		}
		if (Visit[E] == -1)break;
		int flow = INF;
		for (int i = E; i != S; i = Visit[i])
			flow = min(flow, c[Visit[i]][i] - f[Visit[i]][i]);
		for (int i = E; i != S; i = Visit[i]) {
			ans += flow * d[Visit[i]][i];
			f[Visit[i]][i] += flow;
			f[i][Visit[i]] -= flow;
		}
	}
	cout << ans << endl;
	return 0;
}