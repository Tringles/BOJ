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

int n, m, S, t, cnt, scnt = 1, ans;
int svisited[10005], visited[10005], finish[10005], sn[10005], ind[10005], sw[10005], succ[10005];
vector<vector<int>> v, sv;
stack<int> s;
queue<int> q;

int dfs(int cur) {
	visited[cur] = ++cnt;
	s.push(cur);
	int result = visited[cur];
	for (auto& i : v[cur]) {
		if (!visited[i])result = min(result, dfs(i));
		else if (!finish[i])result = min(result, visited[i]);
	}
	if (result == visited[cur]) {
		while (true) {
			int t = s.top();
			s.pop();
			finish[t] = true;
			sn[t] = scnt;
			sw[scnt]++;
			if (t == cur)break;
		}
		scnt++;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> S >> t;
	v.resize(n + 1);
	sv.resize(n + 1);
	for (int i = 0, p1, p2; i < m; i++) {
		cin >> p1 >> p2;
		v[p1].push_back(p2);
	}
	for (int i = 1; i <= n; i++)if (!visited[i])dfs(i);
	for (int i = 1; i <= n; i++) {
		for (auto& j : v[i]) {
			if (sn[i] != sn[j]) {
				sv[sn[i]].push_back(sn[j]);
				ind[sn[j]]++;
			}
		}
	}
	S = sn[S];
	for (int i = 1; i < scnt; i++) {
		svisited[i] = sw[i];
		if (i == S)succ[i] = true;
		if (!ind[i])q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto& i : sv[cur]) {
			if (succ[cur]) {
				svisited[i] = max(svisited[i], svisited[cur] + sw[i]);
				succ[i] = true;
			}
			if (!(--ind[i]))q.push(i);
		}
	}
	if (succ[sn[t]]) cout << svisited[sn[t]] << endl;
	else cout << 0 << endl;
	return 0;
}