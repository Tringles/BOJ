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

int n, m, k, p1, p2, p3;
int dp[333][333], s[333][333];

int func(int cur, int cnt) {
	if (cur == n)return 0;
	if (cnt == m)return -1;
	int& ret = dp[cur][cnt];
	if (ret != -1)return ret;
	for (int i = cur + 1; i <= n; i++)
		if (s[cur][i])
			ret = max(ret, s[cur][i] + func(i, cnt + 1));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < k; i++) {
		cin >> p1 >> p2 >> p3;
		if (p1 < p2)s[p1][p2] = max(s[p1][p2], p3);
	}
	cout << (func(1, 1) < 0 ? 0 : func(1, 1)) << endl;
	return 0;
}