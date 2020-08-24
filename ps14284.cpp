#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, m, visit[5001], dist[5001], p1, p2, p3, s, f;
vector<vector<pair<int, int>>> v;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	fill(dist, dist + n + 1, INF);
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2 >> p3;
		v[p1].push_back({ p2,p3 });
		v[p2].push_back({ p1,p3 });
	}
	cin >> s >> f;
	dist[s] = 0;
	q.push({ 0,s });
	while (!q.empty()) {
		int cur;
		do {
			cur = q.top().second;
			q.pop();
		} while (visit[cur] && !q.empty());
		if (visit[cur])break;
		for (auto& i : v[cur]) {
			int next = i.first;
			int d = i.second;
			if (dist[cur] + d < dist[next]) {
				dist[next] = dist[cur] + d;
				q.push({ dist[next],next });
			}
		}
	}
	cout << dist[f] << endl;
	return 0;
}
