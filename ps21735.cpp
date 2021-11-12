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

int n, m, s[105];

int solve(int cur, int cnt, int d) {
	int ret = 0;
	if (cnt > m)return 0;
	if (cnt == m) return d;
	ret = max(solve(cur + 1, cnt + 1, d + s[cur + 1]), solve(cur + 2, cnt + 1, d / 2 + s[cur + 2]));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)cin >> s[i];
	cout << solve(0, 0, 1) << endl;
	return 0;
}