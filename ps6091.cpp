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

int n, p[2222], cnt;
priority_queue<PII, vector<PII>, greater<PII>> q;
vector<vector<int>> v;

int find(int x) {
	if (p[x] < 0)return x;
	else return p[x] = find(p[x]);
}
bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return false;
	p[x] = y;
	cnt++;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(p, -1, sizeof(p));
	cin >> n;
	v.resize(n + 1);
	for (int i = 1;i <= n;i++) {
		for (int j = i + 1, p1;j <= n;j++) {
			cin >> p1;
			q.push({ p1,{i,j} });
		}
	}
	while (cnt < n - 1) {
		int dist = q.top().first;
		int y = q.top().second.first;
		int x = q.top().second.second;
		q.pop();
		if (merge(x, y)) {
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}
	for (int i = 1;i <= n;i++) {
		cout << v[i].size() << ' ';
		sort(v[i].begin(), v[i].end());
		for (auto& j : v[i])cout << j << ' ';
		cout << endl;
	}
	return 0;
}