#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<double, double> PD;
typedef pair<ll, ll> PL;
typedef pair<double, pair<double, double>> PDD;
typedef pair<ll, pair<ll, ll>> PLL;
#define endl '\n'
#define INF 2e9
#define LINF 2e15
#define MOD 1000000007

int n, k, m[11], s[11];

void dfs(int cur, int cnt) {
	if (cnt == k) {
		for (int i = 0; i < k; i++)
			cout << m[i] << ' ';
		cout << endl;
		return;
	}
	else {
		int tmp = 0;
		for (int i = cur; i < n; i++) {
			if (tmp == s[i])continue;
			tmp = s[i];
			m[cnt] = s[i];
			dfs(i, cnt + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> s[i];
	sort(s, s + n);
	dfs(0, 0);
	return 0;
}