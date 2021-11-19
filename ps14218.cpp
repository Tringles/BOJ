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

int n, m, k, visited[1005];
vector<vector<int>> v;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0, p1, p2;i < m;i++) {
		cin >> p1 >> p2;
		v[p1].push_back(p2);
		v[p2].push_back(p1);
	}
	cin >> k;
	while (k--) {
		memset(visited, 0, sizeof(visited));
		int p1, p2;cin >> p1 >> p2;
		v[p1].push_back(p2);
		v[p2].push_back(p1);
		q.push(1);
		visited[1] = 1;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (auto& i : v[cur]) {
				if (!visited[i]) {
					visited[i] = visited[cur] + 1;
					q.push(i);
				}
			}
		}
		cout << 0 << ' ';
		for (int i = 2;i <= n;i++)cout << (!visited[i] ? -1 : visited[i] - 1) << ' ';
		cout << endl;
	}
	return 0;
}