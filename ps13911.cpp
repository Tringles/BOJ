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

int n, m, macdist[10005], stardist[10005], visited[10005], check[10005];
int mcnt, scnt, mdist, sdist, ans = INF;
vector<vector<PI>> v;
priority_queue<PI, vector<PI>, greater<PI>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	fill(macdist, macdist + n + 1, INF);
	fill(stardist, stardist + n + 1, INF);
	for (int i = 0, p1, p2, p3;i < m;i++) {
		cin >> p1 >> p2 >> p3;
		v[p1].push_back({ p2,p3 });
		v[p2].push_back({ p1,p3 });
	}
	cin >> mcnt >> mdist;
	for (int i = 0, p1;i < mcnt;i++) {
		cin >> p1;
		check[p1] = 1;
	}
	cin >> scnt >> sdist;
	for (int i = 0, p1;i < scnt;i++) {
		cin >> p1;
		check[p1] = 2;
	}
	for (int i = 1;i <= n;i++) {
		if (check[i] == 1) {
			q.push({ 0,i });
			macdist[i] = 0;
		}
	}
	while (!q.empty()) {
		int cur;
		do {
			cur = q.top().second;
			q.pop();
		} while (!q.empty() && visited[cur]);
		if (visited[cur]) break;
		visited[cur] = true;
		for (auto i : v[cur]) {
			int next = i.first, ndist = i.second;
			if (macdist[next] > macdist[cur] + ndist) {
				macdist[next] = macdist[cur] + ndist;
				q.push({ macdist[next], next });
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		if (check[i] == 2) {
			q.push({ 0,i });
			stardist[i] = 0;
		}
	}
	memset(visited, 0, sizeof(visited));
	while (!q.empty()) {
		int cur;
		do {
			cur = q.top().second;
			q.pop();
		} while (!q.empty() && visited[cur]);
		if (visited[cur]) break;
		visited[cur] = true;
		for (auto i : v[cur]) {
			int next = i.first, ndist = i.second;
			if (stardist[next] > stardist[cur] + ndist) {
				stardist[next] = stardist[cur] + ndist;
				q.push({ stardist[next], next });
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		if (!check[i]) {
			if (macdist && stardist && macdist[i] <= mdist && stardist[i] <= sdist)
				ans = min(ans, macdist[i] + stardist[i]);
		}
	}
	if (ans == INF)cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}