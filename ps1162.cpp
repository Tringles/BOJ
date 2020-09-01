#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, m, k, p1, p2, p3, ans;
int dist[10001][22], visit[10001][22];
vector<vector<pair<int, int>>> v;
priority_queue<P, vector<P>, greater<P>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2 >> p3;
		v[p1].push_back({ p2,p3 });
		v[p2].push_back({ p1,p3 });
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++)
			dist[i][j] = INF;
	dist[1][0] = 0;
	q.push({ 0,{1,0} });
	while (!q.empty()) {
		int cur, kcnt;
		do {
			cur = q.top().second.first;
			kcnt = q.top().second.second;
			q.pop();
		} while (!q.empty() && visit[cur][kcnt]);
		if (visit[cur][kcnt])break;
		visit[cur][kcnt] = true;
		for (auto& i : v[cur]) {
			int next = i.first, d = i.second;
			if (kcnt + 1 <= k && dist[next][kcnt + 1] > dist[cur][kcnt]) {
				dist[next][kcnt + 1] = dist[cur][kcnt];
				q.push({ dist[next][kcnt + 1],{next,kcnt + 1} });
			}
			if (dist[next][kcnt] > dist[cur][kcnt] + d) {
				dist[next][kcnt] = dist[cur][kcnt] + d;
				q.push({ dist[next][kcnt],{next,kcnt} });
			}
		}
	}
	ans = INF;
	for (int i = 1; i <= k; i++) {
		if (visit[n][i] && ans > dist[n][i])
			ans = dist[n][i];
	}
	cout << ans << endl;
	return 0;
}
