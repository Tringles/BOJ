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

int n, k, m[11];

void dfs(int cnt) {
	if (cnt == k) {
		for (int i = 0; i < k; i++)
			cout << m[i] << ' ';
		cout << endl;
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			m[cnt] = i;
			dfs(cnt + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	dfs(0);
	return 0;
}
