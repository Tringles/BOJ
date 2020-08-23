#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, m, dp[101][101];

bool func(int a, int b) {
	int& ret = dp[a][b];
	if (ret != -1)return ret;
	if (a == 1 && b == 1)return ret = false;
	if (a > 1)
		for (int i = 1; i < a; i++)
			if (!func(i, a - i))return ret = true;
	if (b > 1)
		for (int i = 1; i < b; i++)
			if (!func(i, b - i))return ret = true;
	return ret = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	cout << (func(n, m) ? 'A' : 'B') << endl;
	return 0;
}