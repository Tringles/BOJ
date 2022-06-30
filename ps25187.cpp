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

int n, m, Q, w[100005], visited[100005], cnt, gcnt, tcnt;
PI g[100005];
vector<vector<int>> v;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> Q;
	v.resize(n + 1);
	for (int i = 1;i <= n;i++)
		cin >> w[i];
	for (int i = 0, p1, p2;i < m;i++) {
		cin >> p1 >> p2;
		v[p1].push_back(p2);
		v[p2].push_back(p1);
	}
	for (int i = 1;i <= n;i++) {
		if (!visited[i]) {
			gcnt++;
			cnt = tcnt = 0;
			visited[i] = gcnt;
			if (w[i])cnt++;
			tcnt++;
			q.push(i);
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				for (auto j : v[cur]) {
					if (!visited[j]) {
						visited[j] = gcnt;
						if (w[j])cnt++;
						tcnt++;
						q.push(j);
					}
				}
			}
			g[gcnt] = { cnt, tcnt };
		}
	}
	for (int i = 0, p1;i < Q;i++) {
		cin >> p1;
		if (g[visited[p1]].first > g[visited[p1]].second - g[visited[p1]].first)
			cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}