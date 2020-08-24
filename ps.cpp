#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, f, s, p1, p2, p3, visit[100001], dist;
vector<vector<pair<int, int>>> v;

void dfs(int cur,int mdist) {
	if (cur == s) {
		cout << visit[cur] - mdist - 1 << endl;
		return;
	}
	for (auto& i : v[cur]) {
		if (!visit[i.first]) {
			visit[i.first] = visit[cur] + i.second;
			dfs(i.first, max(mdist, i.second));
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> f >> s;
	v.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> p1 >> p2 >> p3;
		v[p1].push_back({ p2,p3 });
		v[p2].push_back({ p1,p3 });
	}
	visit[f] = 1;
	dfs(f, 0);
	return 0;
}