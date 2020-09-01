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

int n, m, p1, p2, cnt, snum;
int sn[100001], visit[100001], ind[100001], finish[100001];
vector<vector<int>> v;
vector<vector<int>> scc;
stack<int> s;

int dfs(int cur) {
	visit[cur] = ++cnt;
	s.push(cur);
	int result = visit[cur];
	for (auto& i : v[cur]) {
		if (!visit[i])result = min(result, dfs(i));
		else if (!finish[i])result = min(result, visit[i]);
	}
	if (result == visit[cur]) {
		vector<int> curscc;
		while (1) {
			int t = s.top();
			s.pop();
			curscc.push_back(t);
			finish[t] = true;
			sn[t] = snum;
			if (t == cur)break;
		}
		snum++;
		scc.push_back(curscc);
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2;
		v[p1].push_back(p2);
	}
	for (int i = 0; i < n; i++)
		if (!visit[i])dfs(i);
	for (int i = 0; i < n; i++) {
		for (auto& j : v[i]) {
			if (sn[i] != sn[j])ind[sn[j]]++;
		}
	}
	int result = 0;
	for (int i = 0; i < snum; i++)
		if (!ind[i])result++;
	cout << result << endl;
	return 0;
}
