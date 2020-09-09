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

int dp[4004][4004], ans;
string a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}