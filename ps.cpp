#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n;
ll dp[31][31];

ll func(int w, int h) {
	if (!w && !h)return 1;
	ll& ret = dp[w][h];
	if (ret)return ret;
	if (w && h) {
		ret += func(w, h - 1);
		ret += func(w - 1, h + 1);
	}
	else if (w)ret += func(w - 1, h + 1);
	else ret += func(w, h - 1);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (1) {
		cin >> n;
		if (!n)break;
		memset(dp, 0, sizeof(dp));
		cout << func(n, 0) << endl;
	}
	return 0;
}