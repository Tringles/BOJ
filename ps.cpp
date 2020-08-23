#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	dp[1] = dp[3] = dp[4] = 1;
	for (int i = 5; i <= 1000; i++)
		if (dp[i - 1] + dp[i - 3] + dp[i - 4] != 3)dp[i] = 1;
	cin >> n;
	cout << (dp[n] ? "SK" : "CY") << endl;
	return 0;
}