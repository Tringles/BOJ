#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int ans, dp[1005][16][16], i = 1;
pair<int, int> status[1005];

int func(int cur, int bcnt, int wcnt) {
	if (cur == i)return 0;
	int& ret = dp[cur][bcnt][wcnt];
	if (ret != -1)return ret;
	if (bcnt > 0)ret = max(ret, func(cur + 1, bcnt - 1, wcnt) + status[cur].first);
	if (wcnt > 0)ret = max(ret, func(cur + 1, bcnt, wcnt - 1) + status[cur].second);
	ret = max(ret, func(cur + 1, bcnt, wcnt));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	while (cin >> status[i].first >> status[i].second) { i++; }
	cout << func(0, 15, 15) << endl;
	return 0;
}