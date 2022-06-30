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

int n, m, visited[200005], finish[200005];
vector<vector<int>> v;
queue<PI> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	v.resize(n + 1);
	for (int i = 1;i <= n;i++) {
		int e;cin >> e;
		while (e) {
			v[i].push_back(e);
			cin >> e;
		}
	}
	cin >> m;
	for (int i = 0, p1;i < m;i++) {
		cin >> p1;
		visited[p1] = finish[p1] = 1;
		q.push({ p1, 1 });
	}

	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();
		for (auto i : v[cur]) {
			if (!finish[i] && visited[i] <= v[i].size() / 2) {
				visited[i]++;
				if (visited[i] >= v[i].size() / 2 + v[i].size() % 2) {
					finish[i] = time + 1;
					q.push({ i, time + 1 });
				}
			}
		}
	}

	for (int i = 1;i <= n;i++)cout << (finish[i] ? finish[i] - 1 : -1) << ' ';
	cout << endl;
	return 0;
}