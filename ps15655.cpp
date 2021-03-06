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

int n, k, visit[10001], m[11], s[11];

void dfs(int cur, int cnt) {
	if (cnt == k) {
		for (int i = 0; i < k; i++)
			cout << m[i] << ' ';
		cout << endl;
		return;
	}
	else {
		for (int i = cur; i < n; i++) {
			if (visit[s[i]])continue;
			visit[s[i]] = true;
			m[cnt] = s[i];
			dfs(i, cnt + 1);
			visit[s[i]] = false;
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
