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

int n;
int dist[1005][1005], visit[1005][1005], mp[1005][1005];
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 };
priority_queue<PII, vector<PII>, greater<PII>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			dist[i][j] = INF;
		}
	}
	dist[0][0] = 0;
	q.push({ 0,{0,0} });
	while (!q.empty()) {
		int y, x;
		do {
			y = q.top().second.first;
			x = q.top().second.second;
			q.pop();
		} while (!q.empty() && visit[y][x]);
		visit[y][x] = true;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny<0 || ny>n - 1 || nx<0 || nx>n - 1)continue;
			int d = abs(mp[ny][nx] - mp[y][x]);
			d = max(dist[y][x], d);
			if (dist[ny][nx] > d) {
				dist[ny][nx] = d;
				q.push({ d, { ny,nx } });
			}
		}
	}
	cout << dist[n - 1][n - 1] << endl;
	return 0;
}
