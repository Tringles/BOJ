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

string s;
int dp[5005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	if (s[0] == '0') {
		cout << 0 << endl;
		return 0;
	}
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= s.size(); i++) {
		if (s[i - 1] - '0' > 0)
			dp[i] = dp[i - 1] % 1000000;
		int tmp = (s[i - 1] - '0') + (s[i - 2] - '0') * 10;
		if (9 < tmp && tmp < 27)
			dp[i] += dp[i - 2] % 1000000;
	}
	cout << dp[s.size()] % 1000000 << endl;
	return 0;
}
