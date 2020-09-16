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

int n, m, s, d, p1, p2, p3;
int visit[333], dist[333], w[333][333];
priority_queue<PI, vector<PI>, greater<PI>> q;
queue<int> eq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (1) {
		cin >> n >> m;
		if(!n && !m)break;
		memset(visit, 0, sizeof(visit));
		memset(w, 0, sizeof(w));
		fill(dist, dist + n, INF);
		cin >> s >> d;
		for (int i = 0; i < m; i++) {
			cin >> p1 >> p2 >> p3;
			w[p1][p2] = p3;
		}
		q.push({ 0,s });
		dist[s] = 0;
		while (!q.empty()) {
			int cur;
			do {
				cur = q.top().second;
				q.pop();
			} while (!q.empty() && visit[cur]);
			if (visit[cur])break;
			visit[cur] = 1;
			for (int i = 0; i < n; i++) {
				if (w[cur][i] && dist[i] > dist[cur] + w[cur][i]) {
					dist[i] = dist[cur] + w[cur][i];
					q.push({ dist[i],i });
				}
			}
		}
		eq.push(d);
		while (!eq.empty()) {
			int cur = eq.front();
			eq.pop();
			for (int i = 0; i < n; i++) {
				if (w[i][cur] && dist[i] == dist[cur] - w[i][cur]) {
					eq.push(i);
					w[i][cur] = 0;
				}
			}
		}
		memset(visit, 0, sizeof(visit));
		fill(dist, dist + n, INF);
		q.push({ 0,s });
		dist[s] = 0;
		while (!q.empty()) {
			int cur;
			do {
				cur = q.top().second;
				q.pop();
			} while (!q.empty() && visit[cur]);
			if (visit[cur])break;
			visit[cur] = 1;
			for (int i = 0; i < n; i++) {
				if (w[cur][i] && dist[i] > dist[cur] + w[cur][i]) {
					dist[i] = dist[cur] + w[cur][i];
					q.push({ dist[i],i });
				}
			}
		}
		if (dist[d] == INF)cout << -1 << endl;
		else cout << dist[d] << endl;
	}
	return 0;
}
