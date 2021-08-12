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

int n, m, visit[105], cnt;
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

	visit[1] = true;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto& i : v[cur]) {
			if (!visit[i]) {
				visit[i] = true;
				q.push(i);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}