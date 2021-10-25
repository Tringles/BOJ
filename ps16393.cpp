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

int n, p[2555], cnt;
priority_queue<PII, vector<PII>, greater<PII>> q;
vector<PI> v;

int find(int x) {
	if (p[x] < 0)return x;
	else return p[x] = find(p[x]);
}
bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return false;
	cnt++;
	p[x] = y;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	memset(p, -1, sizeof(p));
	for (int i = 0;i < n;i++) {
		for (int j = 0, p1;j < n;j++) {
			cin >> p1;
			if (j > i) q.push({ p1,{i + 1,j + 1} });
		}
	}
	while (cnt < n - 1) {
		int dist = q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();
		if (merge(x, y)) v.push_back({ x, y });
	}
	for (auto& i : v)cout << i.first << ' ' << i.second << endl;
	return 0;
}