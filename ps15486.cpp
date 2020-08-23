#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, p[2][1500001], dp[1500001];

int t(int cur) {
	if (cur > n)return 0;
	int& ret = dp[cur];
	if (ret)return ret;
	if (cur == n && p[0][cur] == 1)
		return ret + p[1][cur];
	ret = max(ret, t(cur + 1));
	if (cur + p[0][cur] <= n + 1)
		ret = max(ret, t(cur + p[0][cur]) + p[1][cur]);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> p[0][i] >> p[1][i];
	cout << t(1) << endl;
	return 0;
}
