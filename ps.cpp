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

int n, m, p1, p2;
int ind[32005];
vector<vector<int>> v;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2;
		v[p1].push_back(p2);
		ind[p2]++;
	}
	for (int i = 1; i <= n; i++)
		if (!ind[i])q.push(i);
	while (!q.empty()) {
		int cur = q.top();
		q.pop();
		cout << cur << ' ';
		for (auto& i : v[cur])
			if (!(--ind[i]))q.push(i);
	}
	cout << endl;
	return 0;
}
