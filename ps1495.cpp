#include<bits/stdc++.h>
#include<unordered_map>
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

int n, s, m, p[101], dp[101][1001], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) cin >> p[i];
	dp[0][s] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i][j]) {
				if (j + p[i] <= m)dp[i + 1][j + p[i]] = true;
				if (j - p[i] >= 0)dp[i + 1][j - p[i]] = true;
			}
		}
	}
	int flag = false;
	for (int i = 0; i <= m; i++)
		if (dp[n][i])ans = i, flag = true;
	cout << (flag ? ans : -1) << endl;
	return 0;
}
