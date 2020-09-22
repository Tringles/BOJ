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

int n, k, visit[26], ans;
string str[55];

void func(int cur, int cnt) {
	if (cnt == k) {
		int ctr = 0;
		for (int i = 0; i < n; i++) {
			bool flag = false;
			for (int j = 0; j < str[i].size(); j++) {
				if (!visit[str[i][j] - 'a']) {
					flag = true;
					break;
				}
			}
			if (!flag)ctr++;
		}
		ans = max(ans, ctr);
		return;
	}
	for (int i = cur; i < 26; i++) {
		if (!visit[i]) {
			visit[i] = true;
			func(i, cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> str[i];
	if (k < 5)cout << 0 << endl;
	else if (k == 26)cout << n << endl;
	else {
		for (int i = 0; i < n; i++) {
			str[i] = str[i].substr(4, str[i].size());
			for (int j = 0; j < 4; j++)
				str[i].pop_back();
		}
		k -= 5;
		visit[0] = visit['c' - 'a'] = visit['t' - 'a'] = visit['i' - 'a'] = visit['n' - 'a'] = true;
		func(0, 0);
		cout << ans << endl;
	}
	return 0;
}
