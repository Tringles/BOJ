#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

ll t, n, dp[65][10];

ll func(int cur, int cnt) {
	if (cur == n)return 1;
	ll& ret = dp[cur][cnt];
	if (ret)return ret;
	for (int i = 0; i < 10; i++)
		if (cnt <= i)ret += func(cur + 1, i);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		memset(dp, 0, sizeof(dp));
		cout << func(0, 0) << endl;
	}
	return 0;
}