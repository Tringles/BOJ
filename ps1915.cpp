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

int n, m, ans, dp[1005][1005];
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> str;
		for (int j = 0;j < str.size();j++)
			dp[i][j] = str[j] - '0';
	}
	for (int i = 1;i < n;i++)
		for (int j = 1;j < m;j++)
			if (dp[i][j])dp[i][j] += min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
	for (int i = 0;i < n;i++)for (int j = 0;j < m;j++)ans = max(ans, dp[i][j]);
	cout << ans * ans << endl;
	return 0;
}