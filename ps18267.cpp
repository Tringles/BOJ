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

int n, m, p[100005];
char cow[100005];
string ans;

int find(int x) {
	if (p[x] < 0)return x;
	return p[x] = find(p[x]);
}
bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return false;
	p[x] = y;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> cow;
	memset(p, -1, sizeof(p));
	for (int i = 0, p1, p2;i < n - 1;i++) {
		cin >> p1 >> p2;
		if (cow[p1 - 1] == cow[p2 - 1])merge(p1, p2);
	}
	while (m--) {
		int p1, p2;
		char c;
		cin >> p1 >> p2 >> c;
		p1 = find(p1), p2 = find(p2);
		if (p1 != p2)ans.push_back('1');
		else if (cow[p1 - 1] == c)ans.push_back('1');
		else ans.push_back('0');
	}
	cout << ans << endl;
	return 0;
}