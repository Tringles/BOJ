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

int cnt;

vector<int> solution(vector<string> n, vector<string> r, vector<string> s, vector<int> a) {
	vector<int> ret;
	vector<int> ans(n.size() + 1);
	vector<vector<int>> v;
	v.resize(n.size() + 1);
	map<string, int> m;

	m["-"] = 0;
	for (auto i : n)
		m[i] = ++cnt;
	for (int i = 0;i < n.size();i++)
		v[m[n[i]]].push_back(m[r[i]]);

	for (int i = 0;i < s.size(); i++) {
		int cur = m[s[i]], w = a[i] * 100;
		ans[cur] += w;
		while (cur) {
			int par = v[cur][0];
			int cost = w / 10;
			if (!cost) break;
			ans[cur] -= cost;
			ans[par] += cost;
			w = cost;
			cur = par;
		}
	}

	for (int i = 1;i < ans.size();i++)ret.push_back(ans[i]);
	return ret;
}