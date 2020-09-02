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

int t, n, m, w, p1, p2, p3;
int dist[555];
vector<vector<PI>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		bool cycle = false;
		v.clear();
		cin >> n >> m >> w;
		fill(dist, dist + n + 1, INF);
		v.resize(n + 1);
		for (int i = 0; i < m; i++) {
			cin >> p1 >> p2 >> p3;
			v[p1].push_back({ p2,p3 });
			v[p2].push_back({ p1,p3 });
		}
		for (int i = 0; i < w; i++) {
			cin >> p1 >> p2 >> p3;
			v[p1].push_back({ p2,-p3 });
		}
		dist[1] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (auto& k : v[j]) {
					int next = k.first, d = k.second;
					if (dist[next] > dist[j] + d) {
						dist[next] = dist[j] + d;
						if (i == n)cycle = true;
					}
				}
			}
		}
		if (cycle)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
