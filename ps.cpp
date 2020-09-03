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

int n, p1, p2, p3, dp[2][100001];
vector<PII> v;

int func(int state, int cur) {
	if (cur >= n)return 0;
	int& ret = dp[state][cur];
	if (ret != -1)return ret;
	ret = max(ret, func(state, cur + 1));
	ret = max(ret, func(!state, cur + 2) + v[cur].second.second);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> p1 >> p2 >> p3;
		v.push_back({ p1,{p2,p3} });
	}
	cout << func(0, 0) << endl;
	return 0;
}