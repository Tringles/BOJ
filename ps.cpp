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

int n, q, parNode[100005], p[100005], cnt[100005];
vector<PI> v;
stack<int> ans;
set<int> s[100005];

int find(int x) {
	if (p[x] < 0)return x;
	return p[x] = find(p[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (s[y].size() >= s[x].size())swap(x, y);
	for (auto it = s[y].begin(); it != s[y].end(); it++)
		s[x].insert(*it);
	p[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	memset(p, -1, sizeof(p));
	for (int i = 1, p1; i < n; i++) {
		cin >> p1;
		parNode[i + 1] = p1;
	}
	for (int i = 1, p1; i <= n; i++) {
		cin >> p1;
		s[i].insert(p1);
	}
	for (int i = n + q - 2, p1, p2; i >= 0; i--) {
		cin >> p1 >> p2;
		v.push_back({ p1,p2 });
	}
	reverse(v.begin(), v.end());
	for (auto& i : v) {
		int cmd = i.first, node = i.second;
		if (cmd == 1) {
			int cNode = parNode[node];
			merge(node, cNode);
		}
		else ans.push(s[find(node)].size());
	}
	while (!ans.empty()) {
		cout << ans.top() << endl;
		ans.pop();
	}
	return 0;
}