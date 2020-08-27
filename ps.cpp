#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, s[100001], dp[100001][2], ans = -INF;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> s[i];
	dp[0][0] = s[0];
	dp[0][1] = s[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0] + s[i], s[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + s[i]);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			ans = max(ans, dp[i][j]);
	cout << ans << endl;
	return 0;
}